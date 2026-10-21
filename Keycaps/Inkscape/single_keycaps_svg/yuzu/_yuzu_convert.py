"""Convert Inkscape keycap SVGs into Yuzu Playground-compatible vector legends.

Yuzu's uploader (VectorUpload) takes every <path d> in the file, joins them, and
uses the root viewBox. Transforms, strokes, styles, <text>, shapes are ignored, and
d must be <= 100k chars. So we output: root viewBox + plain filled <path>s in
absolute coordinates, one file per colour (Yuzu vector layers are single colour).
"""
import base64, copy, re, sys
from pathlib import Path
from lxml import etree
from picosvg.svg import SVG
from picosvg.svg_types import SVGPath
from picosvg.svg_pathops import skia_path
import pathops
from fontTools.ttLib import TTCollection
from fontTools.pens.svgPathPen import SVGPathPen
from fontTools.pens.transformPen import TransformPen

SVGNS = "http://www.w3.org/2000/svg"
NS = {"s": SVGNS}
SCALE = 100.0  # output units per mm
DROP_ID = re.compile(r"^(rect395|rect66|rect18|rect21|rect20|rect2-01)")
HALO = {"SW50_64_color": 70.0}  # knockout width in output units (0.7mm total)
NEAR_BLACK = {"#000000", "#1a1a1a", "#111111", "#050505", "black"}

# Futura Medium as a stand-in for AvantGarde LT Medium (only used for live <text>)
_ttc = TTCollection("/System/Library/Fonts/Supplemental/Futura.ttc")
FONT = next(f for f in _ttc.fonts if f["name"].getDebugName(2) == "Medium" and "Condensed" not in f["name"].getDebugName(1))
GSET, CMAP, UPM = FONT.getGlyphSet(), FONT.getBestCmap(), FONT["head"].unitsPerEm
HMTX = FONT["hmtx"]


def style_get(el, key):
    m = re.search(rf"(?:^|;)\s*{key}\s*:\s*([^;]+)", el.get("style", ""))
    return m.group(1).strip() if m else el.get(key)


def text_to_path(text_el):
    """Replace a <text> with a <path> using Futura Medium outlines."""
    for tspan in text_el.iter(f"{{{SVGNS}}}tspan", f"{{{SVGNS}}}text"):
        if not (tspan.text or "").strip():
            continue
        size = None
        for e in (tspan, text_el):
            fs = style_get(e, "font-size")
            if fs:
                size = float(fs.replace("px", ""))
                break
        x = float(tspan.get("x", text_el.get("x", 0)))
        y = float(tspan.get("y", text_el.get("y", 0)))
        anchor = style_get(tspan, "text-anchor") or style_get(text_el, "text-anchor") or "start"
        s = size / UPM
        chars = tspan.text.strip()
        width = sum(HMTX[CMAP[ord(c)]][0] for c in chars) * s
        if anchor == "middle":
            x -= width / 2
        elif anchor == "end":
            x -= width
        pen = SVGPathPen(GSET)
        for c in chars:
            g = CMAP[ord(c)]
            GSET[g].draw(TransformPen(pen, (s, 0, 0, -s, x, y)))
            x += HMTX[g][0] * s
        p = etree.Element(f"{{{SVGNS}}}path", d=pen.getCommands(), style="fill:#000000")
        if text_el.get("transform"):
            p.set("transform", text_el.get("transform"))
        return p
    return None


def preprocess(src: Path):
    tree = etree.parse(str(src))
    root = tree.getroot()
    raster = []
    for el in list(root.iter()):
        if not isinstance(el.tag, str):
            continue
        tag = etree.QName(el).localname
        ns = etree.QName(el).namespace
        if ns and ns != SVGNS:  # sodipodi:namedview etc.
            el.getparent().remove(el)
            continue
        if tag == "image":
            raster.append(el.get("{http://www.w3.org/1999/xlink}href") or el.get("href"))
            el.getparent().remove(el)
            continue
        if DROP_ID.match(el.get("id", "")) or "filter:url" in el.get("style", "") or el.get("filter"):
            if el.getparent() is not None:
                el.getparent().remove(el)
            continue
        if tag == "text":
            p = text_to_path(el)
            parent = el.getparent()
            if p is not None:
                parent.replace(el, p)
            else:
                parent.remove(el)
            continue
        # zero-length stray paths (e.g. "M 208.33,62.89")
        if tag == "path" and not re.search(r"[LlHhVvCcSsQqTtAaZz]", el.get("d", "")) and len(re.findall(r"[-\d.]+", el.get("d", ""))) <= 2:
            el.getparent().remove(el)
            continue
    # strip inkscape/sodipodi attributes so picosvg doesn't complain
    for el in root.iter():
        if not isinstance(el.tag, str):
            continue
        for a in ("style", "stroke-width"):
            if el.get(a):
                el.set(a, re.sub(r"(\d)px", r"\1", el.get(a)))
        for a in list(el.attrib):
            if a.startswith("{") and not a.startswith(f"{{{SVGNS}}}") and "xlink" not in a:
                del el.attrib[a]
    return etree.tostring(root).decode(), raster


def norm_color(c):
    c = (c or "#000000").lower()
    if len(c) == 4:
        c = "#" + "".join(ch * 2 for ch in c[1:])
    return "#000000" if c in NEAR_BLACK else c


def convert(src: Path, outdir: Path):
    xml, raster = preprocess(src)
    pico = SVG.fromstring(xml).topicosvg(allow_text=True)
    vb = [float(v) for v in pico.svg_root.get("viewBox").split()]
    W, H = vb[2] * SCALE, vb[3] * SCALE
    by_color = {}
    for el in pico.svg_root.iter(f"{{{SVGNS}}}path"):
        col = norm_color(el.get("fill"))
        if el.get("fill-opacity") and float(el.get("fill-opacity")) < 0.05:
            continue
        sp = skia_path(SVGPath(d=el.get("d")).as_cmd_seq(), el.get("fill-rule", "nonzero"))
        by_color.setdefault(col, []).append(sp)
    outputs = []
    multi = len(by_color) > 1
    merged_by = {}
    for col, paths in by_color.items():
        m = pathops.Path()
        pathops.union(paths, m.getPen(), fix_winding=True)
        merged_by[col] = m.transform(SCALE, 0, 0, SCALE, -vb[0] * SCALE, -vb[1] * SCALE)
    if src.stem in HALO and "#000000" in merged_by:
        # original used a blurred white glow behind the black art; emulate with a hard knockout
        knock = pathops.Path(merged_by["#000000"])
        knock.stroke(HALO[src.stem], pathops.LineCap.ROUND_CAP, pathops.LineJoin.ROUND_JOIN, 4)
        knock.convertConicsToQuads()
        u = pathops.Path(); pathops.union([knock, merged_by["#000000"]], u.getPen()); 
        for col in merged_by:
            if col != "#000000":
                r = pathops.Path(); pathops.difference([merged_by[col]], [u], r.getPen()); merged_by[col] = r
    stem = src.stem
    for col, merged in sorted(merged_by.items(), key=lambda kv: kv[0] != "#000000"):
        d = svg_d(merged)
        if not d:
            continue
        name = f"{stem}_{col.lstrip('#')}.svg" if multi else f"{stem}.svg"
        svg = (f'<svg xmlns="{SVGNS}" viewBox="0 0 {round(W)} {round(H)}" width="{W/SCALE:.2f}mm" height="{H/SCALE:.2f}mm">'
               f'<path fill="{col if multi else "#000000"}" d="{d}"/></svg>\n')
        (outdir / name).write_text(svg)
        outputs.append((name, len(d)))
    for j, href in enumerate(raster):
        if href and href.startswith("data:image/"):
            mime, b64 = href[5:].split(";base64,", 1)
            ext = mime.split("/")[1]
            rn = f"{stem}_raster{j or ''}.{ext}"
            (outdir / rn).write_bytes(base64.b64decode(b64))
            outputs.append((rn, -1))
    return outputs


def fmt(v):
    s = f"{v:.1f}"
    return s.rstrip("0").rstrip(".") if "." in s else s


def svg_d(path):
    out = []
    for verb, pts in path:
        pts = " ".join(f"{fmt(x)} {fmt(y)}" for x, y in pts)
        if verb == pathops.PathVerb.MOVE: out.append(f"M{pts}")
        elif verb == pathops.PathVerb.LINE: out.append(f"L{pts}")
        elif verb == pathops.PathVerb.QUAD: out.append(f"Q{pts}")
        elif verb == pathops.PathVerb.CUBIC: out.append(f"C{pts}")
        elif verb == pathops.PathVerb.CLOSE: out.append("Z")
        else: raise ValueError(verb)
    return "".join(out)


if __name__ == "__main__":
    srcdir, outdir = Path(sys.argv[1]), Path(sys.argv[2])
    outdir.mkdir(parents=True, exist_ok=True)
    for f in sorted(srcdir.glob("*.svg")):
        try:
            for name, n in convert(f, outdir):
                print(f"{f.name:40s} -> {name:45s} {'raster' if n < 0 else str(n) + ' chars'}")
        except Exception as e:
            print(f"{f.name:40s} !! {type(e).__name__}: {e}")

# Status
Realeased: 2026-10-11  
# C64-Keyboard
A mechanical keyboard for the C64.
*	<b>Reset</b>: The keyboard can generate RESET and EXROM RESET signals.
*	<b>Kernal switching</b>: The keyboard can switch between multiple Kernals on an EPROM Kernal adapter.
*	<b>OLED display</b>: An I²C OLED display can be connected to the keyboard.
*	<b>Piezo buzzer</b>: The keyboard includes a piezo buzzer for signaling.
*	<b>USB keyboard</b>: The keyboard can be operated as a USB keyboard for VICE and BMC64.
*	<b>RGB lighting</b>: The keyboard can produce a light show using a WS2812B RGB LED strip.
*	<b>Power LED</b>: The C64's power LED can be connected to the keyboard on either the left or right side and can be made to blink.
*	<b>Additional buttons</b>: Two additional buttons beside the shorter space bar provide additional control functions.
*   <b>Ultimate 64 elite II buttons</b>: Control MENU/FREEZE/RESET with the keyboard. No extra buttons need to be installed

After about 21 months of work, the day has finally come: I’m releasing my Commodore C64 keyboard project on GitHub!

I haven’t been working on it full-time, of course, but I’ve still put several person-months of work into it (most of it for documentation). And I’ve certainly spent a few thousand euros along the way (so you don't have to).

<p align="center"><img src="https://github.com/svenpetersen1965/C64-Keyboard/blob/main/pictures/4637_-_C64%26USB_KBD.JPG" width="600" alt="C64-Keyboard and the USB-Keyboard version"></p>
<p align="center">The C64 mechanic Keyboard and the USB-Keyboard version for VICE and BMC64</p>

My goal was to build a complete keyboard, including the keycaps, and figure out a way for others with some DIY skills to build one, too, without having to spend anywhere near as much money.

Let me be clear, though: this isn’t meant to be a cheap replacement for an original C64 keyboard. It’s for people who use a C64, an Ultimate 64, or another C64-compatible system and enjoy mechanical keyboards. If you’d like to build your own keyboard and add some extra functionality to your setup, this project might be just what you’re looking for.

The documentation is around 80 pages long, but most of it consists of pictures, and you don't need to read every single page. I'd really appreciate it, though, if you took the time to understand the important parts. Otherwise, I might end up providing support for years to come, and I'd rather spend that time working on new projects!

The bill of materials (BOM) is quite flexible. You don't need all the components; you can populate only the parts required for your intended setup. I've designed the BOM to make this as straightforward as possible.

However, you should decide which features you need before ordering the components. Even if you fully populate the board, none of the unused circuits will interfere with the keyboard's normal operation.

I'd like to draw your attention to the following important sections of the documentation:
*	<b>Hardware description</b>: <a href="https://github.com/svenpetersen1965/C64-Keyboard/blob/main/C64%20Keyboard%20Standard%20Version/Rev.%202/pdf/C64_Keyb_v2.pdf">Versions without hot-swap sockets</a> for the keyboard switches.
*	<b>Hardware description</b>: <a href="https://github.com/svenpetersen1965/C64-Keyboard/blob/main/C64%20Keyboard%20with%20Hot%20Swap%20Sockets/Rev.%202/pdf/C64_Keyb_HSw_v2.pdf">Versions with hot-swap sockets</a> for the keyboard switches.
*	<b>C64 Keyboard Connector PCB</b>: <a href="https://github.com/svenpetersen1965/C64-Keyboard/blob/main/C64%20Keyboard%20connector%20PCB/Rev.%200/pdf/C64KBConPCB_v0.pdf">Module description</a>. The adapter for the ribbon cable (not required for USB keyboards).
* <b>3D printables</b>: <a href="https://github.com/svenpetersen1965/C64-Keyboard/blob/main/3D%20printables/pdf/C64KB_3D_printables_v1.pdf">Module Description</a>. The mounting frame and the USB keyboard case.
*	<b>Cables</b>: <a href="https://github.com/svenpetersen1965/C64-Keyboard/blob/main/Cables/pdf/Which%20cables%20do%20I%20need.pdf">Which Cables Do I Need?</a>
*	<b>Cables</b>: <a href="https://github.com/svenpetersen1965/C64-Keyboard/blob/main/Cables/pdf/Cable_making.pdf">Cable Making</a>
*	<b>A short guide to making your own keycaps</b>: <a href="https://github.com/svenpetersen1965/C64-Keyboard/blob/main/Keycaps/pdf/How_to_keycaps.pdf">How To: Keycaps</a>.
*	<b>Software documentation</b>: <a href="https://github.com/svenpetersen1965/C64-Keyboard/blob/main/Software/pdf/C64KB_SW_v0.00.pdf">How to use, configure and program the firmware</a>.

The cost of building this project depends on your needs. Buying a fiber laser or a UV printer just for this project probably doesn't make much sense. A dye-sublimation printer is considerably cheaper, but even that isn't essential if you can get hold of pre-printed dye-sublimation transfer paper. The keycaps you can make with this method can look really impressive!

<p align="center"><img src="https://github.com/svenpetersen1965/C64-Keyboard/blob/main/Keycaps/pictures/6108_-_DyeSub_keyboard_C%3D.JPG" width="600" alt="C64 Keyboard with Dye Sub Keycaps"></p>
<p align="center">C64 Keyboard with Dye Sub Keycaps</p>

The hot plate required for dye sublimation costs around €27 (as of October 2026). You may already have most of the other tools you need.

<p align="center"><img src="https://github.com/svenpetersen1965/C64-Keyboard/blob/main/Keycaps/pictures/5320_-_DyeSub_Work_bench.JPG" width="600" alt="Work bench for Dye Sub Keycaps"></p>
<p align="center">Work bench for Dye Sub Keycaps</p>

I've also covered several other ways to add legends to the keycaps, including fiber laser engraving, UV decals and direct UV printing, as well as using original C64 keycaps or Blingboard64 keycaps.

Programming the microcontroller (a Pro Micro) requires nothing more than a USB cable and the free Arduino IDE.

You can easily customize the firmware to suit your needs by enabling or disabling compiler options before uploading it. Simply uncomment or comment out the relevant lines using //.

The only real downside of this project is that you need to solder SMD components (0805, SOT-23, SO-8, SO-14 and SO-16, with a 1.27 mm pin pitch). However, using the hot plate I mentioned earlier for making dye-sublimation keycaps actually makes this quite enjoyable. You can find tutorials on hot-plate soldering on YouTube.

<b>Note</b>: You might like the <a href="https://github.com/svenpetersen1965/C64-Keycap-Handling-Tray/">C64 Keycap Handling Tray</a>, which is a by-product of this project. It is a 3D printable tray, which allows you to keep the oversight of a complete set of C64 keycaps (original and DIY).

# Calculation (as of Oct. 19th, 2025)
The BOM value of the standard keyboard is 98,61€ and 106,99€ of the hot swap keyboard. This does not include shipping and tariffs. Also, the printing of the keycap legends is not included. There are both modules (pro micro and PCF8575) included. The optional LED strip and OLED display are not part of the calculation. 

The price for the switches can vary a lot. I have used the value for Cherry Hyperglide black switches (0.40€) I have already tried switches for 0,23€ each (Gateron g pro milk yellow), which also worked. It really depends on your taste.

The price for the 1U keycaps also vary a lot. I have calculated price of 0,24€, which is the normal price. I have already bought some for 0,13€, too. 

The stabilizers are not cheap components, either. I have assumed 7,79€ for the 7U stabilizer and 6,69€ for the 2U one. I have also used  sets of 1x7U and 4x2U screw mounted stabilizers for 10,99€. Probably, you get that for even less (7€?).

The BOM value of the Connector PCB plus ribbon cable is 3.60€, which is already included in the above calculations for the keyboard.

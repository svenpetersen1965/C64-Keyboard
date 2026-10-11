# Status
Realease on the go. 2026-10-11  
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

This is a work in progress. I am sharing some files in advance. A full release will happen soon. 

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

# Status
* Hardware tested: done
* Software tested: done
* Upload all design files: done
* Documentaion: completed, except "Howto: Keycaps"
  
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
*	Hardware module description: Versions with and without hot-swap sockets for the keyboard switches.
*	C64 Keyboard Connector PCB: Module description.
*	Which Cables Do I Need?
*	How To: Keycaps: A short guide to making your own keycaps.
*	Software documentation: How to use and configure the firmware.

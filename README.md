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

This project has already been a long journey (19 months) and required quite a bit of a budget, already. My guess, it was about 3000€. I have spent it, so you don't have to.

<p align="center"><img src="https://github.com/svenpetersen1965/C64-Keyboard/blob/main/pictures/4637_-_C64%26USB_KBD.JPG" width="600" alt="C64-Keyboard and the USB-Keyboard version"></p>
<p align="center">The C64 mechanic Keyboard and the USB-Keyboard version for VICE</p>

It started end of January 2025. So, I was not satisfied with the shift lock circuit in Rev. 0. It worked perfectly from a lab power supply, but in some real C64, it had shift lock activated on power on. It seems to depend on the supply voltage. So I have made a rev. 1 and a rev. 2. Also, I have derived a version with hot swap sockets for the keyboard switches. The switches and their characteristics are a big thing and a matter of personal preference and of course, matter of the price. I have seen switches for 0.25€ and also for 0.95€ each. The stabilizer for the space bar and the RETURN key can also be crazy expensive. You can get both for 7€ or easily 25€.

The PBT blank key caps are about 0.24€ each, the space bar is 1.25€.
Putting the legend on the blank keycaps is still a thing. I have tried laser engraving and dye sub. Probably nobody will spend the money on a laser engraver (1400€ for a fiber laser engraver).
Dye sublimation is pretty ok, but a bit of work. The legend is printed mirrored on a special paper with dye sub ink. One can cut out the legends and heat press them onto the key caps. That does not require crazy equipment, if you buy a sheet with the legends already.

Laser engraving is nice. The legends only work on light key caps and the legends are not perfectly black.
Both methods produce legends, that are mechanically stable.

UV decals will be available to purchase. The decals are durable and the positioning is no witchcraft.

Next is  UV printing. That would require an expensive UV printer, the legends can even be white on black keycaps, which neither laser engraving nor dye sublimation can do. The legends don’t rub off, easily. I have tested one manufacturer and will soon be testing a second one. 

Original keycaps with little adapters are also possible. The 1.5U (wide) key caps like the function keys are different from the modern key caps, which have the switch connection in the middle. The original 1.5U key caps have two switch connections and use the right (the RESTORE key the left) one of them. Those keys have two switch positions.

Dye sublimation is under evaluation. It looks pretty good, already. It is probably the most time consuming method, but it is not very hard to do, it does not require really expensive tools (in case you get a sheet of transfer paper printed, or you own a dye sublimation printer). The keycaps don't wear off easily, the contrast of dark print on light keycaps is pretty good, even multi color keycaps are possible.  

The plastic frame is 3D printed in two parts. It is screwed to the PCB and is pretty rigid. They keyboard does not bend or wrap while typing.

The original space bar is 9U wide. I did not find that available anywhere. So I decided for a 7U space bar and two additional 1U switches (1U+7U+1U = 9U).

The two additional keys will do kernal switching together with the RESTORE key, you don’t want to switch kernals accidentally. The RESTORE key will also work as RESET, when it is held for 3 seconds or as EXROM RESET, when held for 5 seconds.

I did not want to do a light show/LED strips in the beginning, but there were some GPIO pins left on the (Arduino) pro micro, so I finally changed my mind. A WS2812B type LED strip can be connected and it will do 10 different color/brightness effects.
A piezo buzzer is on the PCB, an OLED display can be connected. A power LED can be connected to the PCB (left and right).

For the Ultimate C64 or C64 Ultimate, the two additional switches can also act as Freeze and Menu (when pressed together with RESTORE). Holding RESTORE for 3 seconds will act as reset.

It is also possible to let the keyboard act like a USB keyboard for VICE. It works with an English or German keyboard layout.
There are SMD ICs, passives and transistors on board. I just could not prevent it on a keyboard.
The keyboard cable is a ribbon cable with a small PCB at one side. That is easier and cheaper to produce, than a cable with crimp terminals.

The micro controller on this keyboard is a pro micro and it can be programmed with the Arduino IDE and a usb cable.

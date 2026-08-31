/* C64 Keyboard Software */
/* https://github.com/svenpetersen1965 */
/*
  Version History
  v0.00: initial release
*/


#define versionString "v0.00"

/* ======= user configuration preprocessor macros ===================================== */

/* ====== un-comment the used type of OLED display ore none =========================== */
//#define OLED091                  // 0.91" OLED Display, SSD1306, 128x32 pixel, I²C
//#define OLED096                  // 0.96" OLED Display, SSD1306, 128x64 pixel, I²C
//#define OLED130                  // 1.30" OLED Display, SH1106,  128x64 pixel, I²C

//#define OLEDturn                // turn OLED display 180°, if mechanically required 

/* ====== play the Commodore jingle at powre on ====================================== */
#define playKeepingUp              // play the "Are you keeping up.." jingle on startup

/* ====== un-commwnt only one of these USB keyboard layouts to activae USB-Keyboard 
   if the keyboard should connect to a mainboard via pin header, do not active USB keyboard at all */
// #define KB_US                     // USB HID Keyboard US Layout (positional) for Vice
// #define KB_DE                     // USB HID Keyboard German Layout (positional) for Vice
// #define KB_SE                     // USB HID Keyboard Swedish Layout (positional) for Vice
// #define KB_BMC64                  // USB HID Keyboard BMC64 Layout (positional) for BMC64/Raspberry Pi C64 emulation

/* ====== the ultimate 64 has a pinheader "buttons". ================================= */ 
/*  This preprocessor macro will activate controlling the buttons via pin header J2    */
// #define Ultimate                  // use J2 A13, 14, 15 as button left (freeze), menu, right (reset)

/* ====== WS2812B RGB LRD strip (aka neopixel) ======================================= */ 
// #define RGB                          //neopixel (WS2812) RGB strip

// customizable parameters for the RGB LED strip:
#define numRGB       23               // a strip of <num> RGB LEDs. number of LEDs on your strip
#define effectLen    46               // the effect length needs to be longer or equal than numRGB.
                                      // can be higher than numRGB, a higher number produces a smoother effect                     
#define RGBbright    32               // basic brightness of the RGB strip (0 = lowest, 255 = brightest)
#define RGBspeed     0                // speed of the fade effect (0 = fastest)

/* Kernal names */
// These are the names of the 8 kernals, which will be displayed on the OLED display (in case attached)
// NOT LONGER THAN 10 CHARACTERS !!!! 
//     maximum -->          <--length

#define KrnName1 "Kernal #1" // name of Kernal #1 being displayed on the OLED display
#define KrnName2 "Kernal #2" // name of Kernal #2 being displayed on the OLED display
#define KrnName3 "Kernal #3" // name of Kernal #3 being displayed on the OLED display
#define KrnName4 "Kernal #4" // name of Kernal #4 being displayed on the OLED display
#define KrnName5 "Kernal #5" // name of Kernal #5 being displayed on the OLED display
#define KrnName6 "Kernal #6" // name of Kernal #6 being displayed on the OLED display
#define KrnName7 "Kernal #7" // name of Kernal #7 being displayed on the OLED display
#define KrnName8 "Kernal #8" // this will not be displayed in case a short board adapter is used, leave as is.
/*
#define KrnName1 "Commodore" // name of Kernal #1 being displayed on the OLED display
#define KrnName2 "JiffyDOS" // name of Kernal #2 being displayed on the OLED display
#define KrnName3 "JaffyDOS" // name of Kernal #3 being displayed on the OLED display
#define KrnName4 "DolphinDOS" // name of Kernal #4 being displayed on the OLED display
#define KrnName5 "SpeedDOS" // name of Kernal #5 being displayed on the OLED display
#define KrnName6 "Kernalv2.1" // name of Kernal #6 being displayed on the OLED display
#define KrnName7 "Exos v3" // name of Kernal #7 being displayed on the OLED display
#define KrnName8 "TurboAcc."
*/

/* ====== Logo on OLED on start ===================================================== */
#define Logo64               // Logo "64" on OLED display
//#define Logo20               // Logo "VIC-20" on OLED display

/* ====================== End of user definable preprocessor macros ================= */

//do not change:
#define numRGBmodes 10               // number of RGB modes

// defining the displays
#ifdef OLED091                     //0.91" OLED with SSD1306 controller and 128x32 pixel
  #define OLED
  #define SCREEN_WIDTH 128         // screen width in pixel 
  #define SCREEN_HEIGHT 32         // screen height in pixel
  #define SSD1306                  // type of OLED controller
#endif

#ifdef OLED096                     //0.96" OLED with SSD1306 controller and 128x64 pixel
  #define OLED
  #define SCREEN_WIDTH 128         // screen width in pixel
  #define SCREEN_HEIGHT 64         // screen height in pixel
  #define SSD1306                  // type of OLED controller
#endif

#ifdef OLED130                     //1.3" OLED with SH1106 controller and 128x64 pixel
  #define OLED
  #define SCREEN_WIDTH 128         // screen width in pixel
  #define SCREEN_HEIGHT 64         // screen height in pixel
  #define SH1106                   // type of OLED controller
#endif

// if one of the keyboard layouts is activated, then activate USBkeyboard
#ifdef KB_US
  #define USBkeyboard                  // this enables a USB keyboard, which is suitable for VICE
  #define KB Keyboard
#endif

#ifdef KB_DE
  #define USBkeyboard                  // this enables a USB keyboard, which is suitable for VICE
  #define KB Keyboard
#endif

#ifdef KB_SE
  #define USBkeyboard                  // this enables a USB keyboard, which is suitable for VICE
  #define KB Keyboard
#endif

#ifdef KB_BMC64                        
  #define USBkeyboard                  // this enables a USB keyboard, which is suitable for BMC64/RaspberryPi
  #define KB BootKeyboard              // BMC64 requires a boot keyboard
#endif

// defining some strings. Each should not be longer than 10 characters
// These could be a name of the kernal images in the EPROOM 
#ifdef OLED
  typedef char msgString[11];
  const msgString  kernalNames[10] = { {KrnName1},             // names of the kernals
                                       {KrnName2},
                                       {KrnName3},
                                       {KrnName4},
                                       {KrnName5},
                                       {KrnName6},
                                       {KrnName7},
                                       {KrnName8},
                                       {"USB-KeyB"},
                                       {"Ultimate"}
  };
#endif

#ifdef OLED
  //                              -->          <--
  const msgString Messages[11] = { {"Reset"},                   // messages shown on screen
                                   {"EXROMReset"},
                                   {"RestoreFix"},
                                   {"RGB Mode -"},
                                   {"RGB Mode +"},
                                   {"US posit."},
                                   {"DE posit."},
                                   {"SE posit."},
                                   {"Freeze"},
                                   {"Menu"},
                                   {"BMC64 p."}
  };
#endif

#include <EEPROM.h>                     // Library for accessing the (non-volatile) EEPROM 
#include <Wire.h>                       // import Wire library 
#include <avr/pgmspace.h>               // for accessing the sine table

// #include <LiquidCrystal_I2C.h>       // import LiquidCrystal_I2C library
#ifdef OLED
  #include <Adafruit_GFX.h>             // https://github.com/adafruit/Adafruit-GFX-Library
  #ifdef SSD1306
    #include <Adafruit_SSD1306.h>       // https://github.com/adafruit/Adafruit_SSD1306
    #define tCol SSD1306_WHITE
  #endif
  #ifdef SH1106
    #include <Adafruit_SH110X.h>        // https://github.com/adafruit/Adafruit_SH110X
    #define tCol SH110X_WHITE
  #endif
#endif

#ifdef USBkeyboard                      // the PCF8575 is the I²C 16 bit IO extender for the keyboard scan
  #include <PCF8575.h>                  // https://github.com/RobTillaart/PCF8575
  #define PCF_Addr 0x20                 // the I²C address of it.  
  
  #include <HID-Project.h>              // https://github.com/NicoHood/HID
  #include <HID-Settings.h> 
#endif

#ifdef RGB                              // the NeoPixel library is required for the WS2812B LED strips
  #include <Adafruit_NeoPixel.h>        // https://github.com/adafruit/Adafruit_NeoPixel
#endif

// pin definitions
#define nRestore 4
#define buzzer   5
#define rgbPin   6
#define nC64res  8
#define pwrLed   9
#define nExrom   10
#ifndef Ultimate
  #define kswA13   15
  #define kswA14   14
  #define kswA15   16
#else
  #define uFreeze  15
  #define uMenu    14
  #define uReset   16
#endif
#define shortBrd A0
#define nPrev    A1
#define nNext    A2
#define PCFint   7

// definition of the RESTOREfix puls trail 
#define numPulses      5          // number of pulses
#define pulseDuration  30         // duration/period of a pulse in milli seconds

#ifdef Ultimate
  #define uTime 300               // 300ms button down duration
#endif

#ifdef OLED
  // Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
  #define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
  #ifdef SSD1306
    // Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
    Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET); // start SSD1306 OLED display
  #endif
  #ifdef SH1106
    Adafruit_SH1106G display = Adafruit_SH1106G(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET); // start SH1106G OLED display
  #endif
#endif

#ifdef RGB
  Adafruit_NeoPixel strip(numRGB, rgbPin, NEO_GRB + NEO_KHZ800);                                 // initialize RGB LED strip
#endif

#ifdef USBkeyboard  
  PCF8575 pcf(PCF_Addr);                            // initialize the PCF8587 I/O expander for (USB) Keyboard Scan
#endif

#ifdef OLED
  /* ==== The 64 logo ==== */
  #ifdef Logo64
    #define LOGO_HEIGHT   30
    #define LOGO_WIDTH    34
    static const unsigned char PROGMEM logo_bmp[] =
    { B00000000, B00000000, B11111001, B11100000, B00000000,
    B00000000, B00000001, B11110011, B11001000, B00000000,
    B00000000, B00000011, B11100111, B10011000, B00000000,
    B00000000, B00000111, B11001111, B00111000, B00000000,
    B00000000, B00001111, B10011110, B01111000, B00000000,
    B00000000, B00011111, B00111100, B01111000, B00000000,
    B00000000, B00111110, B01111000, B01111000, B00000000,
    B00000000, B01111100, B11110000, B01111000, B00000000,
    B00000000, B11111001, B11100000, B01111000, B00000000,
    B00000001, B11110011, B11000000, B01111000, B00000000,
    B00000011, B11100111, B11000000, B01111000, B00000000,
    B00000111, B11001111, B11000000, B01111111, B11000000,
    B00001111, B10011111, B11111111, B11111111, B10000000,
    B00011111, B00111111, B11111111, B11111111, B00000000,
    B00111110, B01111111, B11111111, B11111110, B00000000,
    B00111100, B10000111, B11111111, B11111100, B00000000,
    B01111000, B00000001, B11110000, B01111000, B00000000,
    B01111000, B00000000, B11110000, B01111000, B00000000,
    B01110000, B00000000, B01111000, B01111000, B00000000,
    B11110000, B00000000, B01111000, B01111000, B00000000,
    B11110000, B00000000, B01111000, B01111000, B00000000,
    B11110000, B00000000, B01111000, B01111000, B00000000,
    B01111000, B00000000, B01111000, B01111000, B00000000,
    B01111000, B00000000, B11111000, B01111000, B00000000,
    B01111100, B00000001, B11110000, B01111000, B00000000,
    B00111111, B00000111, B11110000, B01111000, B00000000,
    B00011111, B11111111, B11100000, B01111000, B00000000,
    B00001111, B11111111, B11000000, B01111000, B00000000,
    B00000111, B11111111, B00000000, B01111000, B00000000,
    B00000000, B11111000, B00000000, B01111000, B00000000 };
  #endif
  #ifdef Logo20
    /* https://javl.github.io/image2cpp/
       VIC-20_Logo_used.png
       100x31
       Canvas background color: White
       original size
       invert
       binary
       Brightness / alpha threshold: 128
       0 degrees
       Flip Image: no
       3. output:
       Draw mode: Horizontal - 1 bit per pixel
       Code output format: Arduino code
       Swap bits in bytes (MSB-LSB)
       Byte Prefix: 0x
       Separator between bytes: ,
       Bytes Per Row: 16
    */
    #define LOGO_HEIGHT   31
    #define LOGO_WIDTH    100
    static const unsigned char PROGMEM logo_bmp[] =  {
      0x1f, 0x83, 0xf9, 0xfc, 0x00, 0x1f, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0x87, 0xfb, 
      0xfc, 0x00, 0xf0, 0x60, 0x00, 0x07, 0xfe, 0x01, 0xff, 0xc0, 0xff, 0xcf, 0xff, 0xfc, 0x03, 0x3f, 
      0xe0, 0x00, 0x0c, 0x01, 0x03, 0x00, 0x60, 0x83, 0xc8, 0x7c, 0x1c, 0x07, 0xe1, 0xe0, 0x00, 0x1f, 
      0xff, 0x87, 0xff, 0xe0, 0x83, 0xc8, 0x7c, 0x1c, 0x1e, 0x00, 0xe0, 0x00, 0x30, 0x07, 0x88, 0x00, 
      0xf0, 0xc3, 0xd8, 0x7c, 0x1c, 0x38, 0x00, 0xe0, 0x00, 0x60, 0x03, 0x88, 0x00, 0xf0, 0x43, 0xd0, 
      0x74, 0x1c, 0x30, 0x00, 0xe0, 0x00, 0x40, 0x03, 0x98, 0x70, 0xf0, 0x43, 0xd0, 0x74, 0x1c, 0x60, 
      0x00, 0xe0, 0x00, 0x43, 0xc3, 0x98, 0xf8, 0x70, 0x41, 0xd0, 0x74, 0x1c, 0xc0, 0x1f, 0xff, 0xfe, 
      0x43, 0xc3, 0x98, 0xe8, 0x70, 0x41, 0xf0, 0x74, 0x1c, 0x80, 0xff, 0xc0, 0x04, 0x43, 0xc3, 0x90, 
      0xe8, 0x70, 0x41, 0xf0, 0xf4, 0x1d, 0x01, 0x80, 0xff, 0xfc, 0x43, 0xc3, 0x90, 0xe8, 0x70, 0x41, 
      0xf0, 0xf4, 0x1d, 0x03, 0x00, 0x80, 0x18, 0x43, 0xc3, 0x90, 0xe8, 0x70, 0x61, 0xf0, 0xf4, 0x1e, 
      0x06, 0x00, 0x80, 0x30, 0x7f, 0x43, 0x90, 0xe8, 0x70, 0x21, 0xf0, 0xe4, 0x1e, 0x06, 0x00, 0x80, 
      0x60, 0x00, 0x43, 0x90, 0xe8, 0x70, 0x21, 0xe0, 0xe4, 0x1e, 0x0e, 0x00, 0x80, 0xc0, 0x00, 0x43, 
      0x90, 0xe8, 0x70, 0x20, 0xe0, 0xe4, 0x1e, 0x0e, 0x00, 0xff, 0xc0, 0x00, 0xc3, 0x90, 0xe8, 0x70, 
      0x20, 0xe0, 0xe4, 0x1e, 0x0e, 0x00, 0xc1, 0xe0, 0x03, 0x83, 0x90, 0xe8, 0x70, 0x20, 0xe1, 0xe4, 
      0x1e, 0x0f, 0x00, 0xff, 0xf0, 0x0e, 0x07, 0x10, 0xe8, 0x70, 0x20, 0xe1, 0xe4, 0x1e, 0x0f, 0x00, 
      0x80, 0xf8, 0x18, 0x0c, 0x10, 0xe8, 0x70, 0x30, 0xe1, 0xe4, 0x1e, 0x04, 0x80, 0x80, 0x7c, 0x30, 
      0x18, 0x10, 0xe8, 0x70, 0x10, 0xe1, 0xc4, 0x1e, 0x06, 0x60, 0x80, 0x3e, 0x60, 0x60, 0x10, 0xe8, 
      0x70, 0x10, 0xc1, 0xc4, 0x1d, 0x03, 0x3f, 0x80, 0x1e, 0x41, 0xc0, 0x10, 0xe8, 0x70, 0x10, 0x41, 
      0xc4, 0x1d, 0x01, 0x87, 0xff, 0xfc, 0x43, 0x80, 0x10, 0xe8, 0x70, 0x10, 0x41, 0xc4, 0x1d, 0x80, 
      0xf3, 0xe0, 0x00, 0x43, 0x80, 0x10, 0xe8, 0x70, 0x10, 0x43, 0xc4, 0x1c, 0xc0, 0x1f, 0xe0, 0x00, 
      0x43, 0xff, 0xd8, 0xf8, 0x70, 0x10, 0x03, 0xc4, 0x1c, 0x60, 0x00, 0xe0, 0x00, 0x43, 0xff, 0xd8, 
      0xf8, 0x70, 0x18, 0x03, 0xc4, 0x1c, 0x30, 0x00, 0xe0, 0x00, 0x40, 0x03, 0xd8, 0x70, 0xe0, 0x08, 
      0x03, 0x84, 0x1c, 0x18, 0x00, 0xe0, 0x00, 0x40, 0x03, 0xc8, 0x00, 0xc0, 0x08, 0x03, 0x84, 0x1c, 
      0x0e, 0x00, 0xc0, 0x00, 0x40, 0x03, 0x8c, 0x00, 0x80, 0x08, 0x03, 0x04, 0x18, 0x03, 0xc0, 0x80, 
      0x00, 0x7f, 0xff, 0x07, 0xff, 0x00, 0x0f, 0xfe, 0x07, 0xf0, 0x00, 0x7f, 0x80, 0x00, 0x00, 0x00, 
      0x00, 0xf8, 0x00
    };
  #endif
#endif // OLED

#define URL_Line1 "https://github.com/"
#define URL_Line2 "svenpetersen1965/"

/* constants */
const bool recover_empty = true;     //enable recover to Kernal one, in case an empty/not working kernal was selected
const int  NumKernal = 8;            //This is the highest valid Kernal number
const int resetCount = 1500;         // count 1.5 seconds of RESTORE Key before Reset is performed
const int EXROMCount = 3000;         // count 3.0 seconds of RESTORE Key before Reset is performed
const int restoreFix = 100;          // count 300ms of RESTORE Key before restore fix is performed 
const int Sig_time = 500;            // constant for signalling duration

// states for restoreSemaphore 
#define rIdle  0                     // the RGB routine is executed, keyboard scan, display refresh 
#define rFix   1                     // calling the RESTORE fix function
#define rReset 2                     // performing a C64 reset
#define rExrom 3                     // performing a C64 EXROM reset
#define kPrev  4                     // the "previous" key + RESTORE was detected
#define kNext  5                     // the "next" key  + RESTORE was detected
#define mNext  6                     // the "previous" key was detected
#define mPrev  7                     // the "next" key was detected
#define sig1   8                     // signal (Power LED and buzzer): Ready for RESET
#define sig2   9                     // signal (Power LED and buzzer): Ready for EXROM RESET

// timing 
#define Debounce   50                 // Debounce Time in ms
#define KBinterval 8                  // keyboard scan every 8 ms: 125 times per second
 
// =============== EEPROM addresses ============================
#define eeKernal 0                    // last Kernal 
#define eeRGB    1                    // last RGB mode 

// USB HID Keyboard ============================================


/*Variables*/
// volatile for use in interrupt
volatile bool kPlus = false;             // semaphore for next kernal
volatile bool kMinus = false;            // semaphore for previous kernal
volatile bool mPlus = false;             // semaphore for next led mode
volatile bool mMinus = false;            // semaphore for previous led mode
volatile bool refresh = false;           // semaphore for display refresh
volatile int  refreshCntDwn = 0;         // milli second count down for refresh
volatile int  restoreSemaphore = rIdle;  // Semaphore for commuication with the loop()
volatile bool tick01sec  = false;        // ticks every 0.1 seconds
volatile bool doKBscan = false;          // semaphore for triggering a keyboard scan every 16ms
volatile bool scanFound = false;         // for detecting C64 keyboard scans

byte KOffset = 0;                        // offset for kernal number
byte KNumber = 0;                        // Kernal number
byte KAddr = 0;                          // Address bits for Kernal
int  countup = 0;                        // counter for restore key time measurement
int  KMax;                               // holds the highest Kernal Number
byte modeNumber;                         // number of the RGB mode executes 
bool USBkbActive = false;                // true, when USB keyboard is activated

volatile boolean tick_1s = 0;            // this flag is set every 1sec by the timer1 ISR
volatile int t1_ticks = 0;               // counts the timer1 interrupts 
volatile int msCntDwn = 0;               // milli seconds countdown (counts to zero)

bool exromMode = 0;                      // exrom mode for reset
int kaddr = 0;                           // kernam address bits (A13..15)

// returns the value of the timer 1ms countdown 
int getMsCntDwn( void ) {
  int result;

  cli();                // disable interrupt
  result = msCntDwn;
  sei();                // enable interrupt
  return result;
}

// set the value of the timer 1ms countdown 
void setMsCntDwn( int value ) {
   cli();                // disable interrupt
   msCntDwn = value;
   sei();                // enable interrupt
}

// set milisecond count down for display refresh
void setRefreshCntDwn( int value ) {
   cli();                // disable interrupt
   refreshCntDwn = value;
   sei();                // enable interrupt
}

// Timer (1ms) driven wait. Waits <value> milli seconds
void waitMs( int value ) {
  setMsCntDwn( value );
  while (getMsCntDwn() > 0 );
}

//  returns true in case a display refresh countdown is still active.
bool activeRefresh( void ) {
  bool result = false;
   cli();                 // disable interrupt
   if (refreshCntDwn > 0) {
    result = true;
   }
   sei();                // enable interrupt
   return result;
}

// definition of the jingle "Are you keeping up with the Commodore?"
typedef struct {
  int note;
  int duration;
} noteType;

#define numNotes 21
#define duration8th 167   //milli seconds, @120bpm
#define stopTime 50

const noteType jingle[numNotes]  = { {3,1}, 
                                     {3,2}, {3,1}, {1,1}, {2,2}, {2,1}, {1,1}, 
                                     {2,1}, {3,1}, {3,4}, {1,1}, {1,1},
                                     {1,1}, {1,1}, {1,1}, {2,1}, {2,1}, {2,1}, {2,1}, {3,1},
                                     {3,6} };
const int frequency[4] = {0, 990, 1114, 1267};

void playJingle( void ) {            // plays the jingle as define previously
  int i;
  
  waitMs( 200 );
  for( i=0; i<numNotes; i++ ) {
         tone( buzzer, frequency[jingle[i].note] );
     waitMs( (jingle[i].duration * duration8th) - stopTime );
     noTone( buzzer );
     digitalWrite( pwrLed, LOW );
     waitMs( stopTime );
     digitalWrite( pwrLed, HIGH );
  }
}

#ifndef Ultimate
/* This function sets the address bits on the pin header J4. Parameter is addr (0..7) */
  void setKswAddr( byte kNumber ) {
    KAddr = kNumber - 1 + KOffset; // Calculate the address bits.
    // For long boards, it should be between 0 and 8,
    // for short boards, it should be 1 to 7, because the first 8k are occupied by the BASIC ROM. 
        
    pinMode( nC64res, OUTPUT );        // do it, while /reset is low 
    waitMs( 5 );                       // wait 5 ms
    
    // the address bits are virtual open collector pins
    if ((KAddr & 1) == 0) {            // A13                  
      pinMode(kswA13, OUTPUT);         // output a "low"
    }
    else {
      pinMode(kswA13, INPUT);          // set to Hi-Z (because it is in input mode)
    }
    if ((KAddr & 2) == 0) {            // A14
      pinMode(kswA14, OUTPUT);         // output a "low"
    }
    else {
      pinMode(kswA14, INPUT);          // set to Hi-Z (because it is in input mode)
    }
    if ((KAddr & 4) == 0) {            // A15
      pinMode(kswA15, OUTPUT);         // output a "low"
    }
    else {
      pinMode(kswA15, INPUT);          // set to Hi-Z (because it is in input mode)
    }
  }
#endif // not Ultimate

/* this function resets the C64 */
void resetC64( bool exromMode ) {
  digitalWrite( pwrLed, 0 );                          // Signalling active: turn Power LED off
  pinMode( nC64res, OUTPUT);                          // issue a reset pulse for the C64
  waitMs( 100 );                                      // 100ms delay
  if (exromMode == 1) {
    pinMode( nExrom, OUTPUT );                        // output low on /EXROM
  }
  waitMs( 300 );                                      // pulse duration: 100+300ms
  pinMode( nC64res, INPUT );                          // deactivate reset line
  if (exromMode == 1) {
    waitMs( 300 );                                    // EXROM should be 300ms longer LOW than RESET
    pinMode( nExrom, INPUT );                         // and input = high impedance (HI-Z)
  }
  digitalWrite( pwrLed, 1 );                          // turn power LED on again.
}

// issues a pulse trail on the RESTORE pin "RESTORTE Fix"
void restorePulses (void) {
  int i;

  digitalWrite( nRestore, 0 );                        // prepare the RESTORE pin for the pulse trail
  for (i=0; i<numPulses; i++ ) {
    pinMode( nRestore, OUTPUT );                      // switching pin mode bwtween OUTPUT and INPUT mimicks an open collector transistor output
    tone( buzzer, 6000 );
    waitMs( pulseDuration/2 );
    pinMode( nRestore, INPUT );                       // pin mode INPUT -> Hi-Z
    noTone(buzzer);
    waitMs( pulseDuration/2 );
  }
}

#ifdef OLED
// displays the 64 Logo on OLED Display
void showLogo(void) {
  display.clearDisplay();                                 // clear OLED
  #ifdef Logo64
  display.drawBitmap(                                     // place the 64 logo in the middle of the OLED
    (display.width()  - LOGO_WIDTH ) /2,
    (display.height() - LOGO_HEIGHT) /2,
    logo_bmp, LOGO_WIDTH, LOGO_HEIGHT, 1);
  #endif
  #ifdef Logo20
    display.drawBitmap(                                     // place the VIC-20 logo in the middle of the OLED
    0,
    (display.height() - LOGO_HEIGHT) /2,
    logo_bmp, LOGO_WIDTH, LOGO_HEIGHT, 1);
  #endif
  display.setTextSize(1);
  display.setTextColor(tCol);
  display.setCursor(SCREEN_WIDTH-30, SCREEN_HEIGHT-8);
  display.print(versionString);
  display.display();                                      // display it!
}

// displays the kernal String on OLED display
void displayKernal(int kernal) {
   
   display.clearDisplay();                                // clear display
   display.setTextSize(2);
   display.setTextColor(tCol);
   display.setCursor(0, 0);                               // cursor top, left
   #ifdef Ultimate
     display.print( kernalNames[9] );                     // print "Ultimate"
   #else  
    if (USBkbActive) {
      display.print( kernalNames[8] );                    // print "USB-KeyB"  
    }
    else {
      display.print( kernalNames[kernal-1] );             // print the Kernal name
    }
   #endif
   display.display();                                     // update display
}  

// display a message string number Message
void displayMsg(int Message) {
  if (SCREEN_HEIGHT == 32) {                              // for 0.91" display
    display.clearDisplay();                               // clear display
    display.setCursor(0, 0);                             // position cursor  (0, 0)
  }
  else {                                                  // all other displays
    display.setCursor(0, 20);                             // position cursor  (0, 20)
  }
  display.setTextSize(2);                                 // set text size and color
  display.setTextColor(tCol);                              
  display.print( Messages[Message] );                     // print message
  display.display();                                      // update display
}

void displayURL( void ){
  display.setCursor(0, SCREEN_HEIGHT-16);
  display.setTextSize(1);
  display.setTextColor(tCol);
  display.print( URL_Line1 );
  display.setCursor(0, SCREEN_HEIGHT-8);
  display.print( URL_Line2 );
  display.display();
}
#endif //#ifdef OLED

#ifdef RGB
  // switch all LEDs off
  void RGBoff (void) {
    int i;
    for (i=0;i<numRGB;i++) {                             // loop numRGB times
      uint32_t rgbcolor = strip.ColorHSV(0,255,0);       // RGB color for off
      strip.setPixelColor(i, rgbcolor);                  // output to LED strip
    }
    strip.show();                                        // update LED strip
  }
  
  // this is circling through the complete color space
  // brightness and delay are parameters
  // the delay will determin the speed. Delay = 0 is fastest 
  void colorSpace( int Brightness, int Delay ) {
    static int counter = 0;
    static int first = 0;
    static int delay_count = 0;
    int i, k;
    uint32_t rgbcolor;

    if (delay_count == 0) {                            // process time delay (for speed of light pattern)
      delay_count = Delay;                             // initialize delay counter
    }
    else {                                             // if it is not zero,
      delay_count--;                                   // count down
    }
    if (delay_count == Delay ) {                       // the change is only executed every <Delay> function calls
      for (i=0; i<effectLen; i++) {                    // for all LEDs
           k = i+first;                                // first is the number offset
           if (k>=effectLen) {                         // calculate k with wrape around
             k = k - effectLen;                        // effect length is at least numLED, but can/should be longer for a less nervous blinking
           }
           rgbcolor = strip.ColorHSV(65536/effectLen*i,255,Brightness);    // color: the hue circle is 0..65535, full saturation(255) and brightness 
           if (k<numRGB) {
              strip.setPixelColor(k, rgbcolor);                            // set the color of the kth LED
           }
       }
       first++;                                                            // count up the offset for next function call
       if (first >= effectLen) {                                           // wrape around, if required
         first = 0;
       }
      strip.show();                                                         // make changes effective (update LED strip)
    }
  }
  
  // this accesses the sine table in program RAM from the neopixel.h
  uint8_t sinetable(uint8_t x) {
    return pgm_read_byte(&_NeoPixelSineTable[x]); // 0-255 in, 0-255 out
  }
  
  // this produces a one color brightness fade in and out
  // brightness and delay are parameters
  // the delay will determine the speed. Delay = 0 is fastest
  void RGBfade( int Brightness, int Delay, int RGBCol ){
    static int counter = 0;
    static int first = 0;
    static int delay_count = 0;
    static int direction = 1;
    int i, k, sine, angle, value;
    uint32_t rgbcolor;

    if (delay_count == 0) {                     // the routine will only execute every (Delay + 1) calls
      delay_count = Delay;                      // restart the count down for that
    }
    else {
      delay_count--;                            // or count down (as long as not zero)
    }
    if (delay_count == Delay ) {                // the change is only executed every <Delay> function calls
      for (i=0; i<effectLen; i++) {             // for all LEDs
           k = i+first;                         // first is the number offset
           if (k>=effectLen) {                  // calculate k with wrape around
             k = k - effectLen;
           }
           if (k<numRGB) { 
              angle = (i * 256) / effectLen;                                // calculate the angle (for sine fuction) 
              sine = (int)sinetable((uint8_t)angle);                        // this reads one byte of the sine table in programm memory
              value = (sine * Brightness) / 256;                            // calculate the value for the brightness
              rgbcolor = strip.ColorHSV(RGBCol,255,(uint8_t)value);         // color: the hue circle is 0..65535, full saturation(255) and brightness 
              strip.setPixelColor(k, rgbcolor);                             // set the color of the kth LED
           }
       }
       if ((direction <0) && (first == 0)) {                                // is direction negative and first LED is reached
          direction = 1;                                                    // this changes the direction to positive
       }
       else if ((direction > 0) && (first >= effectLen - 1)) {              // if direction positive and effect length is reached
          direction = -1;                                                   // change direction to negative 
       }
       first += direction;                                                  // count up/down the offset for next function call
       strip.show();                                                        // make changes effective-   
    }
  }
  
  // hue values of some colors. Interesting read: https://learn.adafruit.com/adafruit-neopixel-uberguide/arduino-library-use
  #define RGBred     0
  #define RGByellow  10923
  #define RGBgreen   21845
  #define RGBcyan    32768
  #define RGBblue    43691
  #define RGBmagenta 51863
  
  // this invokes the LED strip routines depending on the RGB mode.
  void executeRGB( int progNo ) {
     switch( progNo ) {
      case 0: {                              // programm no. 0: all LEDs off
         RGBoff();
         break;
      }
      case 1: {                              // program no. 1: color space sweep/spectrum fast
        colorSpace( RGBbright, 0 );        
        break;
      }
      case 2: {                              // program no. 2: color space sweep/spectrum medium speed
        colorSpace( RGBbright, 1 );         
        break;
      }
      case 3: {                              // program no. 3: color space sweep/spectrum slow
        colorSpace( RGBbright, 2 );        
        break;
      }
      case 4: {                              // program no. 4: red fade wave
        RGBfade( RGBbright, RGBspeed, RGBred );        
        break;
      }
      case 5: {                              // program no. 5: green fade wave
        RGBfade( RGBbright, RGBspeed, RGBgreen );        
        break;
      }
      case 6: {                             // program no. 6: blue fade wave
        RGBfade( RGBbright, RGBspeed, RGBblue );        
        break;
      }
      case 7: {                            // program no. 7: magenta fade wave
        RGBfade( RGBbright, RGBspeed, RGBmagenta );        
        break;
      }
      case 8: {                            // program no. 8: yellow fade wave
        RGBfade( RGBbright, RGBspeed, RGByellow );        
        break;
      }
      case 9: {                            // program no. 9: cyan fade wave
        RGBfade( RGBbright, RGBspeed, RGBcyan );        
        break;
      }
    } 
  }
  
  #ifdef OLED
  // shows the RGB mode on Display
  void displayRGBmode( int RGBmode ) {
    static bool first = true;
    
    displayKernal(KNumber);
    if (SCREEN_HEIGHT == 32) {                      // for 0.91" display
      if (first) {
        displayKernal(KNumber);                     // display kernal Number
        first = false;
      }  
      display.setCursor(0, 16);                     // set cursor (0, 16)
    }
    else {                                          // all other displays
      display.setCursor(0, 20);                     // set cursor (0, 20)
    }
    display.setTextSize(2);                         // set text size and color
    display.setTextColor(tCol);
    display.print( "RGB: " );                       // print "RGB: "
    display.print( RGBmode );                       // print mode number
    display.display();                              // update display
  }
  #endif //OLED
#endif // RGB

/* ===== differnt keyboard matrix patterns for VICE keyboard layout  ============================== */
#ifdef USBkeyboard
  // US positional keyboard layout
  #ifdef KB_US                             
    // Commodore 64 keyboard matrix to USB HID key codes (US layout, positional mapping for VICE)
    // c64Keymap [col][row]
    const uint8_t c64Keymap[8][8] = {
      //            col 0          col 1            col 2      col 3      col 4            col 5          col 6           col7
      // Bit0 col   DEL            RETURN           CRSR R&L   F7         F1               F3             F5              CRSR D&U
                  { KEY_BACKSPACE, KEY_RETURN,      KEY_RIGHT, KEY_F7,    KEY_F1,          KEY_F3,        KEY_F5,         KEY_DOWN }, 
      // Bit1 col   3              W                A          4          Z                S              E               L SHIFT   
                  { KEY_3,         KEY_W,           KEY_A,     KEY_4,     KEY_Z,           KEY_S,         KEY_E,          KEY_LEFT_SHIFT }, 
      // Bit2 col   5              R                D          6          C                F              T               X
                  { KEY_5,         KEY_R,           KEY_D,     KEY_6,     KEY_C,           KEY_F,         KEY_T,          KEY_X }, 
      // Bit3 col   7              Y                G          8          B                H              U               V
                  { KEY_7,         KEY_Y,           KEY_G,     KEY_8,     KEY_B,           KEY_H,         KEY_U,          KEY_V }, 
      // Bit4 col   9              I                J          0          M                K              O               N
                  { KEY_9,         KEY_I,           KEY_J,     KEY_0,     KEY_M,           KEY_K,         KEY_O,          KEY_N }, 
      // Bit5 col   +              P                L          -          .                :              @               ,
                  { KEY_MINUS,     KEY_P,           KEY_L,     KEY_EQUAL, KEY_PERIOD,      KEY_SEMICOLON, KEY_LEFT_BRACE, KEY_COMMA },
      // Bit6 col   POUND          *                ;          HOME       R SHIFT          =              UP Arr.         /
                  { KEY_INSERT,    KEY_RIGHT_BRACE, KEY_QUOTE, KEY_HOME,  KEY_RIGHT_SHIFT, KEY_BACKSLASH, KEY_PAGE_DOWN,  KEY_SLASH },
      // Bit7 col   1              <-               CTRL       2          SPACE            C=             Q               STOP
                  { KEY_1,         KEY_TILDE,       KEY_TAB,   KEY_2,     KEY_SPACE,       KEY_LEFT_CTRL, KEY_Q,          KEY_ESC }
    };
    #define KEY_RESTORE   KEY_PAGE_UP   // define RESTORE key
  #endif

  // German positional keyboard layout
  #ifdef KB_DE
    // Commodore 64 keyboard matrix to USB HID key codes (DE layout, positional mapping for VICE)
    // c64Keymap [col][row]
   const uint8_t c64Keymap[8][8] = {
      //            col 0          col 1            col 2      col 3      col 4            col 5          col 6           col7
      // Bit0 col   DEL            RETURN           CRSR R&L   F7         F1               F3             F5              CRSR D&U
                  { KEY_BACKSPACE, KEY_RETURN,      KEY_RIGHT, KEY_F7,    KEY_F1,          KEY_F3,        KEY_F5,         KEY_DOWN }, 
      // Bit1 col   3              W                A          4          Z                S              E               L SHIFT   
                  { KEY_3,         KEY_W,           KEY_A,     KEY_4,     KEY_Z,           KEY_S,         KEY_E,          KEY_LEFT_SHIFT }, 
      // Bit2 col   5              R                D          6          C                F              T               X
                  { KEY_5,         KEY_R,           KEY_D,     KEY_6,     KEY_C,           KEY_F,         KEY_T,          KEY_X }, 
      // Bit3 col   7              Y                G          8          B                H              U               V
                  { KEY_7,         KEY_Y,           KEY_G,     KEY_8,     KEY_B,           KEY_H,         KEY_U,          KEY_V }, 
      // Bit4 col   9              I                J          0          M                K              O               N
                  { KEY_9,         KEY_I,           KEY_J,     KEY_0,     KEY_M,           KEY_K,         KEY_O,          KEY_N }, 
      // Bit5 col   +              P                L          -          .                :              @               ,
                  { KEY_MINUS,     KEY_P,           KEY_L,     KEY_EQUAL, KEY_PERIOD,      KEY_SEMICOLON, KEY_LEFT_BRACE, KEY_COMMA },
      // Bit6 col   POUND          *                ;          HOME       R SHIFT          =              UP Arr.         /
                  { KEY_NON_US,    KEY_RIGHT_BRACE, KEY_QUOTE, KEY_HOME,  KEY_RIGHT_SHIFT, KEY_BACKSLASH, KEY_END,        KEY_SLASH },
      // Bit7 col   1              <-               CTRL       2          SPACE            C=             Q               STOP
                  { KEY_1,         KEY_TILDE,       KEY_TAB,   KEY_2,     KEY_SPACE,       KEY_LEFT_CTRL, KEY_Q,          KEY_ESC }
    };
    #define KEY_RESTORE   KEY_F12 // define restore key
  #endif
  
  // Swedish positional keyboard layout
  #ifdef KB_SE
    // Commodore 64 keyboard matrix to USB HID key codes (SE layout, positional mapping for VICE)
    // c64Keymap [col][row]
    const uint8_t c64Keymap[8][8] = {
      //            col 0          col 1            col 2      col 3      col 4            col 5          col 6           col7
      // Bit0 col   DEL            RETURN           CRSR R&L   F7         F1               F3             F5              CRSR D&U
                  { KEY_BACKSPACE, KEY_RETURN,      KEY_RIGHT, KEY_F7,    KEY_F1,          KEY_F3,        KEY_F5,         KEY_DOWN }, 
      // Bit1 col   3              W                A          4          Z                S              E               L SHIFT   
                  { KEY_3,         KEY_W,           KEY_A,     KEY_4,     KEY_Z,           KEY_S,         KEY_E,          KEY_LEFT_SHIFT }, 
      // Bit2 col   5              R                D          6          C                F              T               X
                  { KEY_5,         KEY_R,           KEY_D,     KEY_6,     KEY_C,           KEY_F,         KEY_T,          KEY_X }, 
      // Bit3 col   7              Y                G          8          B                H              U               V
                  { KEY_7,         KEY_Y,           KEY_G,     KEY_8,     KEY_B,           KEY_H,         KEY_U,          KEY_V }, 
      // Bit4 col   9              I                J          0          M                K              O               N
                  { KEY_9,         KEY_I,           KEY_J,     KEY_0,     KEY_M,           KEY_K,         KEY_O,          KEY_N }, 
      // Bit5 col   +              P                L          -          .                :              @               ,
                  { KEY_MINUS,     KEY_P,           KEY_L,     KEY_EQUAL, KEY_PERIOD,      KEY_SEMICOLON, KEY_LEFT_BRACE, KEY_COMMA },
      // Bit6 col   POUND          *                ;          HOME       R SHIFT          =              UP Arr.         /
                  { KEY_NON_US,    KEY_RIGHT_BRACE, KEY_QUOTE, KEY_HOME,  KEY_RIGHT_SHIFT, KEY_BACKSLASH, KEY_END,  KEY_SLASH },
      // Bit7 col   1              <-               CTRL       2          SPACE            C=             Q               STOP
                  { KEY_1,         KEY_TILDE,       KEY_TAB,   KEY_2,     KEY_SPACE,       KEY_LEFT_CTRL, KEY_Q,          KEY_ESC }
    };
    #define KEY_RESTORE   KEY_F12
  #endif
  
  // BMC64 positional keyboard layout
  #ifdef KB_BMC64
    // Commodore 64 keyboard matrix to USB HID key codes (DE layout, positional mapping for VICE)
    // c64Keymap [col][row]
   const uint8_t c64Keymap[8][8] = {
      //            col 0          col 1            col 2      col 3      col 4            col 5          col 6           col7
      // Bit0 col   DEL            RETURN           CRSR R&L   F7         F1               F3             F5              CRSR D&U
                  { KEY_BACKSPACE, KEY_RETURN,      KEY_RIGHT, KEY_F7,    KEY_F1,          KEY_F3,        KEY_F5,         KEY_DOWN }, 
      // Bit1 col   3              W                A          4          Z                S              E               L SHIFT   
                  { KEY_3,         KEY_W,           KEY_A,     KEY_4,     KEY_Z,           KEY_S,         KEY_E,          KEY_LEFT_SHIFT }, 
      // Bit2 col   5              R                D          6          C                F              T               X
                  { KEY_5,         KEY_R,           KEY_D,     KEY_6,     KEY_C,           KEY_F,         KEY_T,          KEY_X }, 
      // Bit3 col   7              Y                G          8          B                H              U               V
                  { KEY_7,         KEY_Y,           KEY_G,     KEY_8,     KEY_B,           KEY_H,         KEY_U,          KEY_V }, 
      // Bit4 col   9              I                J          0          M                K              O               N
                  { KEY_9,         KEY_I,           KEY_J,     KEY_0,     KEY_M,           KEY_K,         KEY_O,          KEY_N }, 
      // Bit5 col   +              P                L          -          .                :              @               ,
                  { KEY_MINUS,     KEY_P,           KEY_L,     KEY_EQUAL, KEY_PERIOD,      KEY_SEMICOLON, KEY_LEFT_BRACE, KEY_COMMA },
      // Bit6 col   POUND          *                ;          HOME       R SHIFT          =              UP Arr.         /
                  { KEY_INSERT,    KEY_RIGHT_BRACE, KEY_QUOTE, KEY_HOME,  KEY_RIGHT_SHIFT, KEY_BACKSLASH, KEY_DELETE,     KEY_SLASH },
      // Bit7 col   1              <-               CTRL       2          SPACE            C=             Q               STOP
                  { KEY_1,         KEY_TILDE,       KEY_TAB,   KEY_2,     KEY_SPACE,       KEY_LEFT_CTRL, KEY_Q,          KEY_ESC }
    };
    #define KEY_RESTORE   KEY_F12
  #endif

  // define types for keyboard scan
  typedef uint8_t scan_t[8];

  typedef union {
    uint16_t value;        // 16 bit value of the keyboard ports
    struct {
      uint8_t row;         // P00...P07: rows (read)
      uint8_t col;         // P10...P17: columns
    };
  } port_t;
  
  #define maskBits { B11111110, B11111101, B11111011, B11110111, B11101111, B11011111, B10111111, B01111111 }
  #define scanInit { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff }
  const uint8_t mask[8] = maskBits;
  const scan_t scan_init[8] = scanInit;

  // keyboard click sound for piezo buzzer
  void click( void ) {
    tone(buzzer, 8000);
    waitMs(10);
    noTone(buzzer);
  }

  // the keyboard scan procedure: the bit pattern is scrolled through the column GPIOs, the row bits are read back 
  void keyScan (void) {
    static scan_t scanNow;                                   // present keyboard scan (all 8 rows)
    static scan_t scanPrev  = scanInit;                      // previous keyboard scan (all 8 rows): initialized no key;
    static scan_t lastValid = scanInit;                      // valid keyboard scan: initialized no key;
    uint8_t i, rowNo, colNo;
    port_t port;                                             //  pcf8575 (I²C GPIO module) ports
    uint8_t difference;
    uint8_t bitPattern, scanCode;
    
    for (colNo=0; colNo<8; colNo++ ) {
      port.row = 0xff;                                       // rows: all inputs
      port.col = mask[colNo];                                // columns: mask
      pcf.write16( port.value );                             // write the column mask
      port.value = pcf.read16();                             // read back the actual port value (rows)  
      scanNow[colNo] = port.row;
      if (scanNow[colNo] == scanPrev[colNo] ) {              // the row was constant over two scans (debouncing):
        difference = scanNow[colNo] ^ lastValid[colNo];      // XOR of scan and last valid scan; every change will be marked as 1
        if (difference != 0) {                               // are the read back column bits different from the last valid/debounced column bits?
          bitPattern = 0x01;                                 // yes: initialize bit pattern
          for (rowNo=0; rowNo<8; ++rowNo) {                  // for all 8 rows do
            if ((difference & bitPattern) != 0 ) {           // is the bit different
              scanCode = c64Keymap[colNo][rowNo];            // get the scan code out of the defined keyboard matrix/positional keyboard layouit
              if ((bitPattern & ~scanNow[colNo]) != 0 ) {    // if bit pattern and column scan are equal (the key is pressed)
                // click();
                KB.press( (KeyboardKeycode) scanCode );      // send keyboard press that scan code
                
              } //  if 
              else {                                         // the key is released
                KB.release( (KeyboardKeycode) scanCode );    // send keyboard release that scan code
              } // else
            } // if difference & bitPattern
            bitPattern = bitPattern << 1;                             // shift bit pattern left
          } //  for j
        } // if difference != 0
        lastValid[colNo] = scanNow[colNo];                            // and last valid is column scan 
      } // if (scanNow[i] == scanPrev[i] )
      scanPrev[colNo] = scanNow[colNo];                               // update previous column scan
    } //  for (colNo=0;...
    
 } // void keyscan

 // Sends  Alt + key
 void keyPlusAlt(KeyboardKeycode  key){
   if (USBkbActive) {
     KB.press(KEY_LEFT_ALT);
     KB.press(key);
     waitMs(200);
     KB.release(key);
     KB.release(KEY_LEFT_ALT);
   }
 } //keyPlusAlt
  
  // Sends C= + key (for BMC64 hot key)
  void keyPlusClips(KeyboardKeycode  key){
   if (USBkbActive) {
     KB.press(KEY_LEFT_CTRL);
     waitMs(100);
     KB.press(key);
     waitMs(500);
     KB.release(key);
     waitMs(100);
     KB.release(KEY_LEFT_CTRL);
   }
 } //keyPlusClips

#endif // ifdef USBkeyboard


/* read shortboard jumper J4 and set the KOffset */
 void readJumper( void ) {
   if (digitalRead(shortBrd) == LOW)
   { 
     KOffset = 1; // it is a short board! kernal number offset is 1, since the BASIC is in the lowest 8k of the Kernal ROM
   }
   else {
     KOffset = 0; // it is a long board! kernal number offset is 0, there is no BASIC is in the lowest 8k of the Kernal ROM
   }
 }


/* ===================== Interrup Service Routines ============================= */
// column scan signals will trigger the I²C GPIO module interrupt 
void pcfIRQ (void){                   // the pcf8575 interrupt on pin 7
  scanFound = true;                   // only sets this flag
}

// timer (the heartbeat of the complete software)
ISR(TIMER1_COMPA_vect) {                         // function which will be called when an interrupt occurs at timer 1 every 1ms
  static bool restoreKey = 0;                    // status of the restore key
  static bool oldRestoreKey = 0;                 // previous status of the restore key
  static int  restoreDebounce = 0;               // count down for debouncing the restore key
  static bool restoreState = 0;                  // debounced state of the RESTORE key
  static int  restoreCount = 0;                  // counter for measuring, how long the restore key is pushed down
  static bool prevKey = 0;                       // status of the "Previous" key
  static bool oldPrevKey = 0;                    // previous status of the "Previous" key
  static int  prevDebounce = 0;                  // count down for debouncing the "Previous" key
  static bool nextKey = 0;                       // status of the "Next" key
  static bool oldNextKey = 0;                    // previous status of the "Next" key
  static int  nextDebounce = 0;                  // count down for debouncing the "Next" key
  static int  cntDwn01sec = 100;                 // count down for the 0.1 sec tick
  static int  KBscanCntDwn = KBinterval;         // count down for the keyboard scan tick
  
  // restore key ======================================================================
  restoreKey = (digitalRead(nRestore) == LOW);   // read state from GPIO
  if (restoreKey != oldRestoreKey) {             // if level changed
    restoreDebounce = Debounce;                  // start debounce
  }
  oldRestoreKey = restoreKey;                    // store level in old level
  if (restoreDebounce > 0){                      // debounce not elapsed
    restoreDebounce--;                           // count down debounce counter
    if (restoreDebounce == 0) {                  // debounce elapsed?
      restoreState = restoreKey;                 // change state of restore key
      if (restoreState == true) {                // is restore key pressed?
         restoreCount = 0;                       // start time measurement
      }
    }
  }
  if (restoreState == true) {                   // is restore key pressed?
    restoreCount++;                             // increment time measurement
    if (restoreCount == resetCount) {           // is the count for a reset reached?
      restoreSemaphore = sig1;                  // send "signal 1"  to main loop
    }
    else if (restoreCount == EXROMCount) {      // is the count for an EXROM reset reached?
      restoreSemaphore = sig2;                  // send "signal 2" to the main loop
    }
    else if (restoreCount > 2*EXROMCount) {     // prevent an overflow of the counter
      restoreCount = EXROMCount + 1;            // in case somebody's hobby is pushing RESTORE
    }
  }
                                                // restore key is released
  else if (restoreCount > EXROMCount) {         // if pressed long enoung for EXROMReset     
    restoreSemaphore = rExrom;                  // send signal "exromreset" to the main loop
    restoreCount = 0;                           // reset time measurement
  }
  else if (restoreCount > resetCount) {         //  if pressed long enoung for Reset
    restoreSemaphore = rReset;                  // send signal "Reset" to the main loop
    restoreCount = 0;                           // reset time measurement
  }
  else if (restoreCount > restoreFix) {         //  if pressed long enoung for restore fix
    restoreSemaphore = rFix;                    // send signal
    restoreCount = 0;                           // reset time measurement
  }
  // prev Key ==========================================
  prevKey = (digitalRead(nPrev)== LOW);   // read state from GPIO
  if (prevKey != oldPrevKey) {            // if level changed
    prevDebounce = Debounce;              // start debounce
  }
  
  oldPrevKey = prevKey;                  // store level in old level
  if (prevDebounce > 0){                 // debounce not elapsed
    prevDebounce--;                      // count down debounce counter
    if (prevDebounce == 0) {             // debounce elapsed?
      if (prevKey == true) {             // prev key valid?
        if (restoreState == true) {      // is restore key pressed?
          restoreSemaphore = kPrev;      // signalize "previous kernal"
          restoreCount = 0;              // reset restore count
        }
        else {                           // no restore pressed:
          restoreSemaphore = mPrev;      // signalize "previous mode"
        }
      }
    }
  }
  // next Key ==========================================
  nextKey = (digitalRead(nNext)==LOW);         // read state from GPIO
  if (nextKey != oldNextKey) {          // if level cnhanged
    nextDebounce = Debounce;             // start debounce
  }
  
  oldNextKey = nextKey;                  // store level in old level
  if (nextDebounce > 0){                 // debounce not elapsed
    nextDebounce--;                      // count down debounce counter
    if (nextDebounce == 0) {             // debounce elapsed?
      if (nextKey == true) {             // prev key valid?
        if (restoreState == true) {      // is restore key pressed?
          restoreSemaphore = kNext;      // signalize "next kernal"
          restoreCount = 0;              // reset restore count
        }
        else {                           // no restore pressed:
          restoreSemaphore = mNext;      // signalize "next mode"
        }
      }
    }
  }
  // count down for waitMS()
  if (msCntDwn > 0) {                   // counts down to zero, then stops
     --msCntDwn;
  }
  // count down for display refresh
  if (refreshCntDwn > 0) {
    --refreshCntDwn;
    if (refreshCntDwn == 0) {          // counts down to zero, the sets flag (signal to main loop)
      refresh = true;
    }
  }
  
  // 0.1 sec tick
  if (cntDwn01sec > 0) {                // counts down to zero (100ms)
    cntDwn01sec--;
    if (cntDwn01sec == 0) {
      cntDwn01sec = 100;               // restarts
      tick01sec = true;                // and sets flag (signal to main loop)
    }
  }

  // keyboard scan interval
  if (KBscanCntDwn > 0) {              // counts down to zero
    KBscanCntDwn--;
    if (KBscanCntDwn == 0) {
      KBscanCntDwn =  KBinterval;      // restarts
       doKBscan = true;                // sets flag (signal to main loop)
    }
  }

}

/* =================================================== SETUP =================================================*/
void setup() {
int i;
  digitalWrite( buzzer, LOW );        // piezo buzzer
  digitalWrite( rgbPin, LOW );        // Neopixel RGB-Pin
  digitalWrite( nC64res, LOW );       // /RESET requires an open collector
  digitalWrite( pwrLed, HIGH );       //  Power LED on
  digitalWrite( nExrom, LOW );        // /EXROM requires an open collector

// for both, the kernal switcher and the ultimate button pins, open collector outputs are mimiced 
#ifdef Ultimate
  digitalWrite( uFreeze, LOW );        // Ultimate Button left/freeze           // the button bits are all set low 
  digitalWrite( uMenu,   LOW );        // Ultimate Button Menue                 // for simulation "open collector" outputs 
  digitalWrite( uReset,  LOW );        // Ulrimate button reight/reset          
#else
  digitalWrite( kswA13, LOW );        // kernal ROM upper address bit A13       // the eprom address bits 13..15 are all set low
  digitalWrite( kswA14, LOW );        // kernal ROM upper address bit A14       // for simulation "open collector" outputs 
  digitalWrite( kswA15, LOW );        // kernal ROM upper address bit A15
#endif

  pinMode( nRestore, INPUT );         // RESTORE key input (switches to output for the RESTORE fix pulses)
  pinMode( buzzer, OUTPUT );          // output for the piezo buzzer
  pinMode( rgbPin, OUTPUT );          // output pin  for the WS2812B RGB LED strip
  pinMode( nC64res, INPUT );          // acting like open collector
  pinMode( shortBrd, INPUT );         // shortboard jumper    
  pinMode( pwrLed,OUTPUT );           // power LED output
  pinMode( nExrom, INPUT );           // EXROM: acts like an open collector output. Can pull low as output
  #ifndef Ultimate                    
    pinMode( kswA13, OUTPUT );        // kswA13...15 are all low and the pin mode is output 
    pinMode( kswA14, OUTPUT );        
    pinMode( kswA15, OUTPUT );
  #else
    pinMode( uFreeze, INPUT );        // simulate open colletor
    pinMode( uMenu, INPUT );          // simulate open colletor
    pinMode( uReset, INPUT );         // simulate open colletor
  #endif
  pinMode( nPrev, INPUT );            // the additional key: Previous
  pinMode( nNext, INPUT );            // the additional key: Next
  pinMode( PCFint, INPUT );           // the PFC8575 Interrupt input (goes low if Input bits  have changed)

  readJumper();                       // check if the short board jumper is set and set KOffset
  
  /* ==================== TIMER 1 setup ======================= */
  // Interrupt every 0.001 sec (= 1000Hz) 
  // prescaler = 64
  // Compare Match Register = 250
  // recommended reading: https://nerd-corner.com/arduino-timer-interrupts-how-to-program-arduino-registers/
  
  cli(); // disable interrupts  
  // reset timer1 
  TCCR1A = 0;                          // set TCCR1A register to 0
  TCCR1B = 0;                          // set TCCR1B register to 0
  TCNT1  = 0;                          // reset counter value

  OCR1A = 250;                         // set compare match register of timer 1
  
  TCCR1B |= (0 << CS12);               // 1:64 prescaling for timer1  => CS12 = 0, CS11 = 1, CS10 = 1
  TCCR1B |= (1 << CS11);
  TCCR1B |= (1 << CS10);

  TCCR1B |= (1 << WGM12);              // turn on CTC mode
  TIMSK1 |= (1 << OCIE1A);             // enable timer compare interrupt

  sei();                               // allow interrupts

  #ifndef Ultimate                     // for kernal switcher:
    /* read last selected kernal from eeprom */
    KNumber = EEPROM.read(eeKernal);
    if ((KNumber < 1) || (KNumber > 8-KOffset)) { // if out of range, the first kernal is selected.
      KNumber = 1;                          
      EEPROM.write(eeKernal, KNumber);            // and written back to EEPROM (non volatile)
    }
  #endif

  // read last RGB mode number from EEPROM
  modeNumber = EEPROM.read(eeRGB);
  if ((modeNumber < 0) || (modeNumber > numRGBmodes-1)) { // if out of range, mode #1 is selected.
    modeNumber = 1;
    EEPROM.write(eeRGB, modeNumber);                      // and written back to EEPROM (non volatile)
  }

  exromMode = 0;                               // initialize exrom mode (for reset). 0 = no exrom reset

  #ifndef Ultimate  
    /* Control outputs (for Kernal Adaptor and C64) */
    setKswAddr( KNumber );                       // set the MS address bits for the kernal ROM
  #endif
  resetC64(false);                               // reset the C64 (normal mode)
  
#ifdef USBkeyboard  
  Wire.begin();
   if (!pcf.begin()) {                        // if this fails: error signal
     for(i=0;i<3;i++) {                       // 3x beep
        tone( buzzer, 1000 );                 // 1kz sound on snd_out
        waitMs( 250 );
        noTone( buzzer );
        waitMs( 250 );
      }
      waitMs( 1000 );                         // pause for 1 sec
   }
   attachInterrupt(digitalPinToInterrupt(PCFint), pcfIRQ, FALLING);
   uint16_t port = 0xFFFF;
   pcf.write16( port );                       // configure all 16 GPIOs as inputs by setting them "1"
   waitMs( 5 );                               // weait 5 msecs
   port = pcf.read16();                       // read them back to clear a possible interrupt
   scanFound = false;                         // reset scan found
#endif

#ifdef OLED  
  #ifdef SSD1306  
      if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x32
        for(i=0;i<4;i++) {                             //  fail signal: 4x beep
          tone( buzzer, 1000 );                        // 1kz sound on snd_out
          waitMs( 250 );
          noTone( buzzer );
          waitMs( 250 );
        }
        waitMs( 1000 );                               // pause for 1 sec
        
      }
  #endif    
  #ifdef SH1106  
      if(!display.begin(0x3C, true)) { // Address 0x3C default
        for(i=0;i<5;i++) {            // fail signal: 5x beep
          tone( buzzer, 1000 );       // 1kHz sound on snd_out
          waitMs( 250 );
          noTone( buzzer );
          waitMs( 250 );
        }
        waitMs( 1000 );                               // pause for 1 sec
      }
  #endif
  #ifdef OLEDturn
     display.setRotation(2);
  #endif
    showLogo();                          // Logo on OLED
    // waitMs(5000);                      // delete this after it works properly
#endif

#ifdef RGB
  strip.begin();
  executeRGB( 0 );                       // all off
  executeRGB( modeNumber );              // call RGB execution routine
  strip.show();                          // update LED strip 
#endif

#ifdef playKeepingUp
  playJingle();                        // Are you keeping up with the Commodore
#else
  tone( buzzer, 880 );                 // 880Hz sound on snd_out
  waitMs( 500 );
  noTone( buzzer );
  waitMs( 500 );                      // wait 0.5 seconds
#endif

#ifdef USBkeyboard                    
  KB.begin();                         // start the USB HID Keyboard or Boot Keyboard
  USBkbActive = true;
  waitMs( 100 );
  setRefreshCntDwn(5000);
#endif

#ifdef OLED
  displayKernal(KNumber);
  displayURL();
  display.display();
  // display the configured keyboard layout
  #ifdef KB_US
    displayMsg( 5 );         // display "US posit." 
  #endif
  #ifdef KB_DE
    displayMsg( 6 );         // display "DE posit."
  #endif  
  #ifdef KB_SE               // display "SE posit."
    displayMsg( 7 );
  #endif
  #ifdef KB_BMC64
    displayMsg( 10 );        // display "BMC64 p."
  #endif
#endif
} // setup

void loop() {
  // if an USB Keyboard is defines and noi scan signals from the C64 have been found
  
  #ifdef USBkeyboard
    if (USBkbActive) {                // doKBscan is set by the timer interrupt ebery 8 msecs 
      if (doKBscan) {                 // scan the keyboard (*** times per second, if the timer interrupt has set doKBscan)    
        doKBscan = false;             // reset semaphore doKBscan
        keyScan();                    // scan the keyboard
      }
    }
  #endif

  /* ====== State machine ========================================================== */
  // the timer interrupt controls everything here and modifies the restoreSemaphore
  switch (restoreSemaphore) {
    case rIdle:  {                            // idle state
      if (refresh) {                          // if the OLED display requires a refresh after displaying something else
        refresh = false;                      // reset the flag
        #ifdef OLED
          displayKernal(KNumber);             // display the active kernal 
          displayURL();
          display.display();
        #endif        
      }
      // the tick01sec is set by the timer interrupot every 0.1s, so the stuff, which has to be done every 0.1 sec will be triggered by that
      if (tick01sec) {                        // execute RGB stuff every 0.1 secs 
        tick01sec = false;                    // reset 0.1 sec tick
        #ifdef RGB
          executeRGB( modeNumber );           // call RGB LED strip execution routine
        #endif
      }
      break;
    }
    
    // ==== RESTORE pressed >0.3 secs => 
    case rFix: {                               // C64 ===>  RESTORE fix (RESTORE puls train)                           
      #ifdef OLED
        if (activeRefresh()) {
          displayKernal(KNumber);               // Display Kernal name on OLED
        }
        displayMsg(2);                         // display  "Restore Fix" on display
      #endif
      setRefreshCntDwn(2000);                  // set count down for thew display refresh to 2 seconds
      #ifdef USBkeyboard                       // USB-Keyboard ===>
        if (USBkbActive) {
          KB.press( (KeyboardKeycode) KEY_RESTORE );     // send restore key scan code  on USB keyboard 
          waitMs(100);
          KB.release( (KeyboardKeycode) KEY_RESTORE );
          #ifndef KB_BMC64                                         // if not BMC64
            waitMs(300);
            KB.press( (KeyboardKeycode) KEY_RESTORE );   // the second time
            waitMs(100);
            KB.release( (KeyboardKeycode) KEY_RESTORE );
          #endif
        }
      #endif 
      #ifndef USBkeyboard                      // if it is a real C64 connected
        #ifndef Ultimate                       // and not an ultimate (the ultimate does not require a restore puls train)
          restorePulses();                     // issue a pulse trail on the RESTORE pin.
        #endif
      #endif  
      restoreSemaphore = rIdle;                // reset the restore semaphore to idle
      break;
    }
    
    // ==== RESTORE helt for >3 secs =>
    case rReset: {                             
      #ifdef OLED
        if (activeRefresh()) {
          displayKernal(KNumber);              // Display Kernal name on OLED
        }
        displayMsg(0);                         //  Display "Reset"
      #endif
      setRefreshCntDwn(2000);                  // Set display refresh countdown to 2 secs.
      tone( buzzer, 1000 );                    // 1kHz sound on snd_out
      waitMs( 250 );
      noTone( buzzer );
      #ifdef USBkeyboard                       // USB keyboard?
        #ifndef KB_BMC64                       // if it is not
          keyPlusAlt ( KEY_F9 );               // ALT+F9 is "soft reset" in VICE
        #else
          keyPlusClips (KEY_F1);               // C= + F1 for BMC64 (This has to be defines as soft reset)
        #endif
      #endif
      #ifdef Ultimate                          // in Ultimate 64 mode => Button uRESET
        digitalWrite(uReset, LOW);
        digitalWrite( pwrLed, 0 );             // Signaling active: turn Power LED off
        pinMode( nC64res, OUTPUT);             // resetting the shift lock status
        pinMode(uReset, OUTPUT);               // "press" button uReset 
        waitMs(uTime);                         // wait some time
        pinMode(uReset, INPUT);                // release the button: Switch to Hi-Z
        pinMode( nC64res, INPUT );             // release the reset for the shift lock state flipflop
        digitalWrite( pwrLed, 1 );             // power LED on again
      #else
        resetC64( false );                     // C64: reset C64 in normal mode
      #endif
      restoreSemaphore = rIdle;                // put state machine in idle state  
      break;
    }

    // ==== RESTORE helt for >5 secs =>
    case rExrom: {                             // EXROM reset
      #ifdef OLED
        if (activeRefresh()) {
          displayKernal(KNumber);              // Display Kernal name on OLED
        }
        #ifndef Ultimate
          displayMsg(1);                         // display "EXROM reset" on OLED display
        #else
          displayMsg(0);                         // display "Reset" on OLED display 
        #endif 
      #endif
      #ifdef Ultimate                          // in Ultimate 64 mode => Button uRESET
        digitalWrite(uReset, LOW);
        digitalWrite( pwrLed, 0 );             // Signaling active: turn Power LED off
        pinMode( nC64res, OUTPUT);             // resetting the shift lock status
        pinMode(uReset, OUTPUT);               // "press" button uReset 
        waitMs(uTime);                         // wait some time
        pinMode(uReset, INPUT);                // release the button: Switch to Hi-Z
        pinMode( nC64res, INPUT );             // release the reset for the shift lock state flipflop
        digitalWrite( pwrLed, 1 );             // power LED on again
      #endif
      setRefreshCntDwn(2000);                  // Set display refresh countdown to 2 secs.
      #ifdef USBkeyboard
        #ifndef KB_BMC64                       
          keyPlusAlt ( KEY_F12 );              // VICE  => F12+ALT is "hard reset" in VICE
        #else                                  
          keyPlusClips(  KEY_F3 );             // BMC64 => C= + F3 for BMC64 (This has to be defines as hard reset)
        #endif
      #endif
      resetC64(true);                          // C64   => reset C64, EXROM mode 
      restoreSemaphore = rIdle;                // put state machine in idle state 
      break;
    }
    
    // ==== PREV key with RESTORE detected =>
    case kPrev: {
      #ifdef USBkeyboard
        #ifndef KB_BMC64                      
          keyPlusAlt ( KEY_8 );               // VICE  => <ALT>+<8> is "attach disk image" in VICE
        #else
          keyPlusClips( KEY_F5);              // BMC64 => Send C= + F5 (this needs to be defined in the menu)
        #endif
      #endif
      #ifdef Ultimate                         // Ultimate =>
        #ifdef OLED
          displayMsg(8);                      // Display "FREEZE"
          setRefreshCntDwn(2000);             // Set display refresh countdown to 2 secs.
        #endif
        tone(buzzer, 3000);                   // buzzer tone 3kHz
        digitalWrite(uFreeze, LOW);           // press Ultimate Freeze button
        pinMode(uFreeze, OUTPUT);
        waitMs(uTime);
        pinMode(uFreeze, INPUT);
        noTone(buzzer);
      #else                                   // C64 =>
        readJumper();                         // read short board jumper J4
        if (KNumber > 1) {                    // if kernal number > 1
          KNumber--;                          // decrement it
        }
        else {             
          KNumber = 8 - KOffset;              // if 0: set to highest kernal number (rotate through kernal numbers)
        }
        #ifdef OLED                           // Display Kernal name on OLED
          displayKernal(KNumber);     
          displayURL();        
        #endif
        setKswAddr( KNumber );                // set the MS address bits for the kernal ROM
        resetC64(false);                      // reset the C64 normal mode
        EEPROM.write(eeKernal, KNumber);      // save the chosen Kernalnumber in EEPROM
        waitMs( 1000 );                       // wait for the user releasing the restore key
      #endif                                   
      restoreSemaphore = rIdle;               // put state machine in idle state
      break;
    }

    // ==== NEXT key with RESTORE detected =>
    case kNext: {
      #ifdef USBkeyboard
        #ifndef KB_BMC64
          keyPlusAlt ( KEY_C );                // VICE  =><ALT>+C is "attach cartridge image" in VICE
        #else
          keyPlusClips( KEY_F7);               // BMC64  => Send C= + F7
        #endif
      #endif
      #ifdef Ultimate                          // Ultimate =>
        #ifdef OLED
          displayMsg(9);                       // Display "MENU"
          setRefreshCntDwn(2000);              // Set display refresh countdown to 2 secs.
        #endif
        tone(buzzer, 6000);                    // buzzer tone 6kHz
        digitalWrite(uMenu, LOW);              // press ultimate menu button
        pinMode(uMenu, OUTPUT);
        waitMs(uTime);
        pinMode(uMenu, INPUT);
        noTone(buzzer);
        #ifdef OLED
          displayKernal(KNumber);              // display kernal name
          displayURL();
        #endif
      #else                                    // C64 =>
        readJumper();
        if (KNumber < 8 - KOffset) {           // if kernal number not maximum
          KNumber++;                           // increment it
        }
        else {
          KNumber = 1;                         // else kernal number is 1
        }
        #ifdef OLED
          displayKernal(KNumber);              // display kernal name
          displayURL();
        #endif
        setKswAddr( KNumber );                 // set the MS address bits for the kernal ROM
        resetC64(false);                       // reset the C64 normalmode
        EEPROM.write(eeKernal, KNumber);       // save the chosen Kernalnumber in EEPROM
        waitMs( 1000 );                        // wait 1 sec for releasing RESTORE
       #endif                                  // wait for the user releasing the restore key
      restoreSemaphore = rIdle;                // put state machine in idle state
      break;
    }

    // ==== PREV key without RESTORE detected =>
    case mPrev: {
      #ifdef OLED
        if (activeRefresh()) {
          displayKernal(KNumber);              // display kernal name
        }
      #endif
      if (modeNumber == 0) {                   // if RGB mode == 0 
        modeNumber = numRGBmodes-1;            // set it to maximum
      }
      else {
          modeNumber--;                        // else decrement it
      }
      EEPROM.write(eeRGB, modeNumber);         // store in EEPROM
      #ifdef OLED
        #ifdef RGB
          displayRGBmode(modeNumber);          // display RGB mode
        #endif
        setRefreshCntDwn(2000);                // Set display refresh countdown to 2 secs.
      #endif
      tone(buzzer, 2000);                      // 2kHz tone on buzzer
      waitMs(100);
      noTone(buzzer);
      restoreSemaphore = rIdle;                // put state machine in idle state
      break;
    }

    // ==== NEXT key without RESTORE detected =>
    case mNext: {
      #ifdef OLED
        if (activeRefresh()) {                  
          displayKernal(KNumber);              // display kernal name
        }
      
      #endif
      modeNumber++;                            // increment RGB mode 
      if (modeNumber >= numRGBmodes) {         // if > maximum
        modeNumber = 0;                        // cycle to 0       
      }
      EEPROM.write(eeRGB, modeNumber);         // write it to EEPROM
      #ifdef OLED
        #ifdef RGB
          displayRGBmode(modeNumber);          // display RGB mode
        #endif
        setRefreshCntDwn(2000);                // Set display refresh countdown to 2 secs.
      #endif
      tone(buzzer, 4000);                      // 4kHz tone on buzzer
      waitMs(100);
      noTone(buzzer);
      restoreSemaphore = rIdle;                // put state machine in idle state
      break;
    }
    case sig1: {                               // accoustic and Power LED signal for "Reset held for 3 secs" (normal reset)
      tone(buzzer, 2000);                      // 2kHz tone on buzzer  
      digitalWrite( pwrLed, LOW );             // blink: power LED off
      waitMs(150);
      noTone(buzzer);
      digitalWrite( pwrLed, HIGH );            // power LED on
      restoreSemaphore = rIdle;
      break;
    }
    case sig2: {                               // accoustic and Power LED signal for  "Reset held for 5 secs" (EXROM reset)
      uint8_t i;
      for (i=0; i<2; i++) {
        tone(buzzer, 2000);                    // 2kHz tone on buzzer 
        digitalWrite( pwrLed, LOW );           // blink: power LED off
        waitMs(150);
        noTone(buzzer);
        digitalWrite( pwrLed, HIGH );          // power LED on
        waitMs(50);
      }
      restoreSemaphore = rIdle;
      break;
    }
  } // switch
  
} // end of loop

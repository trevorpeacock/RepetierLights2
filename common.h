#define NUM_LEDS         24

#define RELAY1_PIN 8
#define RELAY2_PIN 7
#define RELAY3_PIN 4
#define RELAY4_PIN 2


//6 pwm:
//2x Extruder
//2x Printer
//2x Overhead

#define P1_EXTRUDER_PIN 11
#define P1_PRINTER_PIN 10
#define P1_OVERHEAD_PIN 9

#define P2_EXTRUDER_PIN 6
#define P2_PRINTER_PIN 5
#define P2_OVERHEAD_PIN 3

//8 + 8 io
//(6) button x 2-3
#define P1_BUTTON_PIN A7

#define P2_BUTTON_PIN A6

//(4) relay x 4
#define P1_POWER_PIN RELAY1_PIN
#define P1_POWER_PIN RELAY2_PIN

//(2) neopixel
#define P1_LEDBAR_PIN A5
#define P2_LEDBAR_PIN A4

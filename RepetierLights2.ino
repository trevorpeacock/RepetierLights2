#include <FastLED.h>

#define NUM_LEDS         24

CRGB p1_status_leds[NUM_LEDS];
CRGB p2_status_leds[NUM_LEDS];

CRGB status_col;
CRGB status_col_background;
byte status_complete;

/*
 * base class, by default blanks all LEDs
 */
class Pattern {
  public:
    //This is called everytime the pattern starts to be used
    virtual void setup() {
    }
    //Called every frame. Pattern should be supplied to provided buffer
    virtual void update(CRGB ledbuffer[]) {
      for (int i = 0; i < NUM_LEDS; i++) {
        ledbuffer[i] = CRGB::Black;
      }
    }
};

class DoorPattern: public Pattern {

    int flow_position;

  public:
    DoorPattern() {
    }

    virtual void setup() {
      flow_position = 0;
    }

    virtual void update(CRGB ledbuffer[]) {
      for (int i = 0; i < NUM_LEDS; i++) {
          ledbuffer[i]=CRGB::Blue;
      }
    }
};

DoorPattern doorpattern = DoorPattern();


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

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);

  status_col=CRGB::Black;
  status_col_background=CRGB::Blue;
  status_complete=128;

  FastLED.addLeds<NEOPIXEL, P1_LEDBAR_PIN>(p1_status_leds, NUM_LEDS);
  FastLED.addLeds<NEOPIXEL, P2_LEDBAR_PIN>(p2_status_leds, NUM_LEDS);

  digitalWrite(RELAY1_PIN, HIGH);
  digitalWrite(RELAY2_PIN, HIGH);
  digitalWrite(RELAY3_PIN, HIGH);
  digitalWrite(RELAY4_PIN, HIGH);
  pinMode(RELAY1_PIN, OUTPUT);
  pinMode(RELAY2_PIN, OUTPUT);
  pinMode(RELAY3_PIN, OUTPUT);
  pinMode(RELAY4_PIN, OUTPUT);
  pinMode(P1_EXTRUDER_PIN, OUTPUT);
  pinMode(P1_PRINTER_PIN, OUTPUT);
  pinMode(P1_OVERHEAD_PIN, OUTPUT);
  pinMode(P2_EXTRUDER_PIN, OUTPUT);
  pinMode(P2_PRINTER_PIN, OUTPUT);
  pinMode(P2_OVERHEAD_PIN, OUTPUT);
  pinMode(P1_BUTTON_PIN, INPUT);
  pinMode(P2_BUTTON_PIN, INPUT);
}

void loop() {
  p1_status_leds[0] = CRGB::Green;
  p2_status_leds[0] = CRGB::Black;
  int a = analogRead(P1_BUTTON_PIN);
  analogWrite(P1_EXTRUDER_PIN, a/4);
  FastLED.show();
  delay(500);
  p1_status_leds[0] = CRGB::Black;
  p2_status_leds[0] = CRGB::White;
  //analogWrite(P1_EXTRUDER_PIN, 10);
  FastLED.show();
  delay(500);
}

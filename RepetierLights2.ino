#include <FastLED.h>
#include "common.h"
#include "status_led.h"
#include "buttons.h"

DoorPattern doorpattern1 = DoorPattern(-1);
DoorPattern doorpattern2 = DoorPattern(1);

ButtonPanel buttonpanel1 = ButtonPanel(P1_BUTTON_PIN);
ButtonController buttoncontroller1(&buttonpanel1, P1_EXTRUDER_PIN, P1_PRINTER_PIN, P1_OVERHEAD_PIN);
ButtonPanel buttonpanel2 = ButtonPanel(P2_BUTTON_PIN);
ButtonController buttoncontroller2(&buttonpanel2, P2_EXTRUDER_PIN, P2_PRINTER_PIN, P2_OVERHEAD_PIN);

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);

  status_col=CRGB::Black;
  status_col_background=CRGB::Blue;
  status_complete=128;

  buttonpanel1.setup();
  buttoncontroller1.setup();
  buttonpanel2.setup();
  buttoncontroller2.setup();
  
  doorpattern1.setup();
  doorpattern2.setup();
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
  //digitalWrite(POWER_RELAY_PIN, power_relay_status);
  buttoncontroller1.update();
  buttoncontroller2.update();
  doorpattern1.update(p1_status_leds);
  doorpattern2.update(p2_status_leds);
  FastLED.show();
  //commandqueue = commandqueue + Serial.readString();
  //check_serial();
  delay(33);
}

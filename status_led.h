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
    int _dir;

  public:
    DoorPattern(int dir) {
      _dir = dir;
    }

    virtual void setup() {
      flow_position = 0;
    }

    virtual void update(CRGB ledbuffer[]) {
      for (int i = 0; i < NUM_LEDS; i++) {
          ledbuffer[i]=CRGB::Black;
      }
      if(flow_position<NUM_LEDS) {
        ledbuffer[_pos(flow_position)]=0x000020;
      } else {
        ledbuffer[_pos(2*NUM_LEDS-2-flow_position)]=0x000020;
      }
      flow_position = (flow_position+1) % (NUM_LEDS*2-2);
    }

    int _pos(int pos) {
      if(_dir==1) return pos;
      return NUM_LEDS-pos-1;
    }
};

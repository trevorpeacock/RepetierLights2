
#define BTN1_THRESHOLD 10
#define BTN2_THRESHOLD 600
#define BTN3_THRESHOLD 1000

class ButtonPanel {

  int _analogpin;
  int _last_read;
  int _last_button;
  int _current_button;
  
  public:
    ButtonPanel(int analogpin) {
      _analogpin = analogpin;
      _last_read = 1023;
    }

    //This is called everytime the pattern starts to be used
    virtual void setup() {
    }
    
    //Called every frame. Pattern should be supplied to provided buffer
    virtual void update() {
      int old_read = _last_read;
      _last_read = analogRead(_analogpin);
      int button = 0;
      if(abs(old_read-_last_read)<10) {
        if(_last_read<BTN1_THRESHOLD) {
          button = 1;
        } else if(_last_read<BTN2_THRESHOLD) {
          button = 2;
        } else if(_last_read<BTN3_THRESHOLD) {
          button = 3;
        }
      }
      _last_button = _current_button;
      _current_button = button;
    }

    virtual int get_hold() {
      return _current_button;
    }

    virtual int get_press() {
      if(_current_button==_last_button)
        return 0;
      return _current_button;
    }
};

class ButtonController {

  ButtonPanel *_panel;
  int _pwm_ext;
  int _pwm_prnt;
  int _pwm_ohead;

  bool _stat_ext;
  bool _stat_print;
  bool _stat_ohead;
    
  public:
    ButtonController(ButtonPanel* panel, int ext, int prnt, int ohead) {
      _panel = panel;
      _pwm_ext = ext;
      _pwm_prnt = prnt;
      _pwm_ohead = ohead;
      _stat_ext = false;
      _stat_print = false;
      _stat_ohead = false;
    }

    //This is called everytime the pattern starts to be used
    virtual void setup() {
    }
    
    //Called every frame. Pattern should be supplied to provided buffer
    virtual void update() {
      _panel->update();
      if(_panel->get_press()==1) {
        _stat_ext = !_stat_ext;
      }
      if(_panel->get_press()==2) {
        _stat_print = !_stat_print;
      }
      if(_panel->get_press()==3) {
        _stat_ohead = !_stat_ohead;
      }

      if(_stat_ext) {
        analogWrite(_pwm_ext, 128);
      } else {
        analogWrite(_pwm_ext, 2);
      }
      if(_stat_print) {
        analogWrite(_pwm_prnt, 128);
      } else {
        analogWrite(_pwm_prnt, 8);
      }
      if(_stat_ohead) {
        analogWrite(_pwm_ohead, 128);
      } else {
        analogWrite(_pwm_ohead, 2);
      }
      
    }
};

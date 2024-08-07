#include "Loader.h"
Loader::Loader(uint8_t servopin, uint8_t buttonpin,uint8_t firing_pin)
  : _servopin(servopin), _buttonpin(buttonpin),_firing_pin(firing_pin) {
  pinMode(_buttonpin, INPUT_PULLUP);
  pinMode(_firing_pin,INPUT_PULLUP);
  _count = 0;
  _angle_increment = 3;
  flag = 0;
  _timeractive=false;
  flag2=0;
}
void Loader::attach(uint8_t _servopin) {
  pinMode(_servopin, OUTPUT);
}
int Loader::getbuttonstate() {
  _buttonstate=digitalRead(_buttonpin);
  return _buttonstate;
}
void Loader::write(uint8_t real_init_angle) {
  fake_init_angle=real_init_angle;
  changed_angle=init_angle;
  if (getbuttonstate() == 1 && flag == 0 && _count <=19) { //press button
    _init_angle = init_angle + _angle_increment;
    _angle_increment=_angle_increment+3;
        _starttime = millis();
        _timeractive = true;
        flag=1;
    }
    else if(getbuttonstate() == 0 && flag == 1){
    _timeractive = false;
    flag=0;
    _count++;
    }
    changed_angle = _init_angle;
    real_init_angle=changed_angle;
}
int Loader::gettime() {
  return _count;
}
int Loader::getwrite() {
  return changed_angle;
}
int Loader::getfiringpinstate(){
_firingstate=digitalRead(_firing_pin);
return _firingstate;
}
void Loader::reset(){
  init_angle=_init_angle;
}
void Loader::firing(){
if(_firingstate==1 && flag2==0){
_endtime = millis();
_duration = _endtime - _starttime;
}
}

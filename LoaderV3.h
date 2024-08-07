#include <stdint.h>
#include <Arduino.h>
class Loader {
private:
  uint8_t _servopin;
  uint8_t _buttonpin;
  uint8_t _count;
  uint8_t _init_angle;
  uint8_t fake_init_angle
  uint8_t real_init_angle;
  uint8_t _angle;
  int _angle_increment;
  int flag;
  uint8_t _firing_pin;
  uint8_t _buttonstate;
  uint8_t _starttime;
  uint8_t _endtime;
  int _timeractive;
  uint8_t _firingstate;
  int flag2;
public:
  uint8_t loaded;
  uint8_t changed_angle;
  Loader(uint8_t servopin, uint8_t buttonpin, uint8_t firing_pin);
  void attach(uint8_t servopin);
  int getbuttonstate();
  int getfiringpinstate();
  void write(uint8_t init_angle);
  void firing();
  void reset();
  int gettime();
  int getwrite();
};

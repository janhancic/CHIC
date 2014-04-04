#include "motor.h"

Motor::Motor(int pin_number, int idle_speed) {
   this->_idle_speed    = idle_speed; 
   this->_pin_number    = pin_number;
   this->_current_speed = 0;
   this->_armed = false;

   if ( _idle_speed > 180 ) {
      //TODO: handle error
   }

   _motor.attach(_pin_number);
   _motor.write(_current_speed);
}

void Motor::start() {
   if (_armed == true) {
      return;
   }
   

   delay(2000);
   while (_current_speed < _idle_speed) {
      _current_speed += 1;
      _motor.write(_current_speed);

      delay(100);
   }

   _armed = true;
}

void Motor::stop() {
   _current_speed = 0;
   _motor.write(_current_speed);
}

/**
 * speed: [0,180]
 */
void Motor::set_speed(int speed) {
   if (speed < 0 || speed > 180) {
      return;
   }

   _current_speed = speed;
   _motor.write(_current_speed);
}

int Motor::get_speed() {
   return _current_speed; 
}

Motor::~Motor() {
   stop();
}

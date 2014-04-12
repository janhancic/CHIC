#include "motor.h"


Motor::Motor(int pin_number, int idle_speed) {
   this->_idle_speed    = idle_speed; 
   this->_pin_number    = pin_number;
   this->_current_speed = 0;
   this->_sync_interval = 50;
   this->_sleep_millis  = 2000;
   this->_on      = false;
   this->_started = false;

   if ( _idle_speed > 180 ) {
      //TODO: handle error
   }

   _motor.attach(_pin_number);
   _motor.write(_current_speed);

   this->_sync_last_time = millis();
}

void Motor::start() {
   long current_time = millis();
   long time_diff = current_time - _sync_last_time;

   if ( _started ) return;

   if( ( _sleep_millis < 0 && time_diff >= _sync_interval ) || ( _sleep_millis >= 0 && time_diff >= _sleep_millis ) ) {
      _sleep_millis = -1;

      if( _current_speed >= _idle_speed ) {
         _current_speed = _idle_speed;
         //TODO: point to other synchronise now
         _started = true;
      }

      _motor.write(++_current_speed);
      _sync_last_time = current_time;

      _on = !_on;
      digitalWrite(13, _on ? HIGH : LOW);
   }
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

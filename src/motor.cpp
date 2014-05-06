#include "motor.h"

class ArmMotorsEvent : public Event {
   private:
      Motor             *_motor;
      Eventdispatcher   *_eventdispatcher;

   public:
      ArmMotorsEvent(Eventdispatcher *eventdispatcher, Motor *motor) {
         _motor = motor;
         _eventdispatcher = eventdispatcher;
      }
   
      EventEnum fire_event() {
         if( _eventdispatcher == NULL ) {
            Serial.print(millis());
            Serial.print("  --> ");
            Serial.println(_motor->get_speed());
            return _motor->do_start() ? CLEAR : KEEP;
         }

         // wait period has passed, now we start telling the motor to increase the speed
         _eventdispatcher->schedule(50, new ArmMotorsEvent(NULL, _motor));
         return CLEAR;
      }
};

Motor::Motor(Eventdispatcher *eventdispatcher, int pin_number, int idle_speed) {
   this->_eventdispatcher = eventdispatcher;
   this->_idle_speed    = idle_speed;
   this->_pin_number    = pin_number;
   this->_current_speed = 0;
   this->_on      = false;
   this->_started = false;

   if ( _idle_speed > 180 ) {
      //TODO: handle error
   }

}

void Motor::start() {
   _motor.attach(_pin_number);
   _motor.write(_current_speed);

   _eventdispatcher->schedule( 2000, new ArmMotorsEvent(_eventdispatcher, this) );
};

bool Motor::do_start() {
   if ( _started ) return true;

   _current_speed += ARMING_SPEED_INC_INTERVAL;

   if( _current_speed >= _idle_speed ) {
      _current_speed = _idle_speed;
      _started = true;
      Serial.print("Motor on pin ");
      Serial.print(_pin_number);
      Serial.println(" started");
   }

   _motor.write(_current_speed);
   return _started;
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

bool Motor::is_started() {
   return _started;
};

Motor::~Motor() {
   stop();
}

#include "WrapArduino.h"
#include "eventdispatcher.h"
#include "WrapServo.h"
#include "WrapSerial.h"

#ifndef __motor_h
#define __motor_h

#define ARMING_SPEED_INC_INTERVAL 1

class Motor {
   private:
      Servo _motor;
      Eventdispatcher *_eventdispatcher;
      int   _pin_number;
      int   _idle_speed;
      int   _current_speed;
      bool  _on;
      bool  _started;

   public:
      Motor(Eventdispatcher *eventdispatcher, int pin_number, int idle_speed);
      
      bool  do_start();
      void  start();
      void  stop();
      void  set_speed(int speed);
      int   get_speed();
      bool  is_started();
      ~Motor();
};

#endif

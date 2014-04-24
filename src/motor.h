#include "WrapArduino.h"
#include "eventdispatcher.h"
#include "WrapServo.h"

#ifndef __motor_h
#define __motor_h

class Motor {
   private:
      Servo _motor;
      Eventdispatcher *_eventdispatcher;
      int   _pin_number;
      int   _idle_speed;
      int   _current_speed;
      long  _sync_interval;
      long  _sleep_millis;
      long  _sync_last_time;
      bool  _armed;
      bool  _arming;
      bool  _on;
      bool  _started;

   public:
      Motor(Eventdispatcher *eventdispatcher, int pin_number, int idle_speed);
      
      void  start();
      void  stop();
      void  set_speed(int speed);
      int   get_speed();
      ~Motor();
};

#endif

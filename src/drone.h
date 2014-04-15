#include "WrapArduino.h"
#include "eventdispatcher.h"
#include "gyro.h"
#include "motor.h"

#ifndef __drone_h
#define __drone_h

class Drone {
   private:
      Eventdispatcher   *_eventdispatcher;
      Gyro              *_gyro;
      Motor             *_motor_fl;
      Motor             *_motor_fr;
      Motor             *_motor_bl;
      Motor             *_motor_br;

   public:
      Drone(Eventdispatcher *eventdispatcher, Gyro *gyro, Motor *fl, Motor *fr, Motor *bl, Motor *br);

      void start();
      void stop();

      ~Drone();
};

#endif

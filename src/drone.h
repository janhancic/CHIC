#include "WrapArduino.h"
#include "motor.h"

#ifndef __drone_h
#define __drone_h

class Drone {
   private:
      Motor _motor_fl;
      Motor _motor_fr;
      Motor _motor_bl;
      Motor _motor_br;

   public:
      Drone();

      void start();
      void loop();

      ~Drone();
};

#endif

#include <WrapArduino.h>
#include <WrapServo.h>

#ifndef __motor_h
#define __motor_h

class MyClass {
   private:
      Servo _my_servo;
      int   _pin_number;
      bool  _light_on;

   public:
      MyClass(int pin_number);

      void toggle();
      bool isOn();
      
      ~MyClass();
};

#endif

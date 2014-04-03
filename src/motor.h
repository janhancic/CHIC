#include <Servo.h>

class Motor {
   private:
      Servo _motor;
      int   _pin_number;
      int   _idle_speed;
      int   _current_speed;
      bool  _armed;
      bool  _arming;

   public:
      Motor(int pin_number, int idle_speed);
      
      void  start();
      void  stop();
      void  set_speed(int speed);
      int   get_speed();
      ~Motor();
};

#ifndef __WRAP_SERVO_H__
#define __WRAP_SERVO_H__

#ifndef _TESTING 
#include "Servo.h"
#else

class Servo {
   public:
   void attach(int);
   void write(int);
};


#endif
#endif /* __WRAP_SERVO_H__ */

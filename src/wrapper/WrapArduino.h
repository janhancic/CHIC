#ifndef __WRAP_ARDUINO_H__
#define __WRAP_ARDUINO_H__

#ifndef _TESTING 
#include "Arduino.h"
#else

#define OUTPUT -10
#define HIGH 1
#define LOW 0

void delay(int time);

#endif
#endif /* __WRAP_ARDUINO_H__ */

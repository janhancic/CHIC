#ifndef __WRAP_ARDUINO_H__
#define __WRAP_ARDUINO_H__

#ifndef _TESTING 
#include "Arduino.h"
#else

#define OUTPUT -10
#define HIGH 1
#define LOW 0

void pinMode(int, int);
void digitalWrite(int, int);

#endif
#endif /* __WRAP_ARDUINO_H__ */

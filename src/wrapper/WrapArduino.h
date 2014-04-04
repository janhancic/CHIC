#ifndef __WRAP_ARDUINO_H__
#define __WRAP_ARDUINO_H__

#ifndef _TESTING 
#include "Arduino.h"
#else

void delay(int);

#endif
#endif /* __WRAP_ARDUINO_H__ */

#ifndef __WRAP_SERIAL_H__
#define __WRAP_SERIAL_H__

#ifndef _TESTING 
#include "HardwareSerial.h"
#else

class ConsoleSerial {
   public:
   static void print(int val) {
      printf("%d", val);
   }
   static void print(const char* str) {
      printf("%s", str);
   }
   static void println(int val) {
      printf("%d\n", val);
   }
   static void println(const char* str) {
      printf("%s\n", str);
   }
};

extern ConsoleSerial Serial;

#endif
#endif /* __WRAP_SERIAL_H__ */

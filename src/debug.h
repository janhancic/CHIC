#ifndef __DEBUG_H
#define __DEBUG_H

#ifdef _xDEBUG
   #undef _DEBUG
#endif

#ifdef _DEBUG

#ifndef _TESTING
   #define PRINT_INIT(arg) \
	   Serial.begin(arg); 
#else
   #define PRINT_INIT(arg)
#endif

#ifdef _TESTING
   #define PRINT(format, ...) \
      printf(format, ##__VA_ARGS__);
   #define PRINTLN(format, ...) \
      printf(format, ##__VA_ARGS__); \
      printf("\n");
#else
   #define PRINT(format, ...) \
      do { \
         char buf[256]; \
         snprintf(buf, 256, format, ##__VA_ARGS__); \
         Serial.print(buf); \
      } while(0);
   #define PRINTLN(format, ...) \
      do { \
         char buf[256]; \
         snprintf(buf, 256, format, ##__VA_ARGS__); \
         Serial.println(buf); \
      } while(0);
#endif /* _TESTING */

#else
   #define PRINT_INIT(arg)
   #define PRINT(fomat, ...)
#endif /* _DEBUG */
#endif /* __DEBUG_H */

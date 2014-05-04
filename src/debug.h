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
      fprintf(stderr, format, ##__VA_ARGS__);
#else
   #define PRINT(format, ...) \
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

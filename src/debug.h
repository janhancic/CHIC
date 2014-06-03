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
   #define PRINT(str) \
      printf(str);
   #define PRINTLN(str) \
      printf("%s\n", str); \
#else
   #define PRINT(str)\
      do { \
         Serial.print(str); \
      } while(0);
   #define PRINTLN(str) \
      do { \
         Serial.println(str); \
      } while(0);
#endif /* _TESTING */

#else
   #define PRINT_INIT(arg)
   #define PRINT(fomat, ...)
#endif /* _DEBUG */
#endif /* __DEBUG_H */

#ifndef __WRAP_WIRE_H__
#define __WRAP_WIRE_H__

#ifndef _TESTING 
#include "Wire.h"
#else

class TwoWire {
   public:
      static void begin();
};


extern TwoWire Wire;
#endif
#endif /* __WRAP_WIRE_H__ */

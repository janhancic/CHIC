#include "WrapArduino.h"
#include "eventdispatcher.h"
#include "I2CDev.h"
#include "MPU6050.h"
#include "Wire.h"

#ifndef __gyro_h
#define __gyro_h

#define X_GYRO_OFFSET 220
#define Y_GYRO_OFFSET 76
#define Z_GYRO_OFFSET -85
#define Z_ACCEL_OFFSET 1788

typedef struct _orientation {
   long w;
   long x;
   long y;
   long z;
} orientation_t;

typedef struct _acceleration {
   long x;
   long y;
   long z;
} acceleration_t;

class Gyro {
   private:
      orientation_t  _orientation;
      acceleration_t _acceleration;

   public:
      Gyro(Eventdispatcher *eventdispatcher);
   
      orientation_t get_orientaion();
      acceleration_t get_acceleration();

      ~Gyro();
};

#endif

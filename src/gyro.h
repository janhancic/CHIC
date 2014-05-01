#include "WrapArduino.h"
#include "eventdispatcher.h"
#include "MPU6050.h"
#include "Wire.h"

#ifndef __gyro_h
#define __gyro_h


#define X_GYRO_OFFSET 220
#define Y_GYRO_OFFSET 76
#define Z_GYRO_OFFSET -85
#define Z_ACCEL_OFFSET 1788

typedef struct _orientation {
   float w;
   float x;
   float y;
   float z;
} orientation_t;

typedef struct _acceleration {
   long x;
   long y;
   long z;
} acceleration_t;

class Gyro {
   private:
      MPU6050          _mpu;
      Eventdispatcher *_eventdispatcher;
      orientation_t    _orientation;
      acceleration_t   _acceleration;

      uint16_t         _fifo_count;
      uint16_t         _packet_size; 
      uint8_t          _fifo_buffer[64];
      uint8_t          _mpu_interrupt_status;


   public:
      Gyro(Eventdispatcher *eventdispatcher);
   
      orientation_t* get_orientation();
      bool setup();
      void set_orientation(long w, long x, long y, long z);
      acceleration_t* get_acceleration();

      void update_data();

      ~Gyro();
};

#endif

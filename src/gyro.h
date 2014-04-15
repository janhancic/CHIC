#include "WrapArduino.h"
#include "I2CDev.h"
#include "MPU6050.h"
#include "Wire.h"

#ifndef __gyro_h
#define __gyro_h

#define X_GYRO_OFFSET 220
#define Y_GYRO_OFFSET 76
#define Z_GYRO_OFFSET -85
#define Z_ACCEL_OFFSET 1788

class Gyro {
   private:
      MPU6050        _mpu;
      Quaternion     _quaternion;
      uint16_t       _packet_size;
      uint16_t       _fifo_count;
      bool           _dmp_ready;
      volatile bool  _mpu_interrupt;
      uint8_t        _mpu_interrup_status;
      uint8_t        _fifo_buffer[64];

      void _dmp_data_ready();
      bool _setup();

   public:
      Gyro();

      void loop();

      ~Gyro();
};

#endif

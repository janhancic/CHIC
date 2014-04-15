#include "gyro.h"

//Gyro::Gyro() {
   //_mpu_interrupt =  false; 
   //_dmp_ready =      false;
//}

//bool Gyro::_setup() {
   //bool dev_status;


   //Wire.begin();
   //TWBR = 24;

   //_mpu.initialize();
   //if( !_mpu.testConnection() ) {
      //return false;
   //}

   //dev_status = _mpu.dmpInitialize();

   //if( dev_status != 0 ) {
      //return false;
   //}

   //_mpu.setXGyroOffset(X_GYRO_OFFSET);
   //_mpu.setYGyroOffset(Y_GYRO_OFFSET);
   //_mpu.setZGyroOffset(Z_GYRO_OFFSET);
   //_mpu.setZAccelOffset(Z_ACCEL_OFFSET);

   //_mpu.setDMPEnabled(true);
   //attachInterrupt(0, dmpDataReady, RISING);
   //_mpu_interrup_status = _mpu.getIntStatus();

   //_dmp_ready = true;
   //_packet_size = mpu.dmpGetFIFOPacketSize();
//}

//void Gyro::_dmp_data_ready() {
   //_mpu_interrupt = true;
//}

//void Gyro::loop() {
   //if( !_dmp_ready ) {
      //return;
   //}

   //if ( !_mpu_interrupt && _fifo_count < _packet_size ) {
      //return;
   //}

   //_mpu_interrupt = false;
   //_mpu_interrup_status = _mpu.getIntStatus();
   //_fifo_count = mpu.getFIFOCount();

   //if( (_mpu_interrup_status & 0x10) || _fifo_count == 1024) {
      //_mpu.resetFIFO();    //should never happen, unless our code is too inefficient
   //} else if( _mpu_interrup_status & 0x02 ) {
      //while( _fifo_count < _packet_size ) _fifo_count = _mpu.getFIFOCount();

      //_mpu.getFIFOBytes(_fifo_buffer, _packet_size);
      //_fifo_count -= _packet_size;
   //}

//}

//Gyro::~Gyro() {
//}

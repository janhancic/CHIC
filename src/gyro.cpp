#include "gyro.h"

bool _mpu_interrupt;

class ReadGyroValuesEvent : public Event {
   private:
      Gyro *_gyro;

   public:
      ReadGyroValuesEvent(Gyro *gyro) {
         this->_gyro = gyro;
      }
   
      EventEnum fire_event() {
         // read actual values from gyro

         //this->_gyro->set_orientation(1, 2, 3, 4);
         // set acceleration
         
         this->_gyro->update_data();

         return KEEP;
      }
};

void Gyro::update_data() {
   if ( !_mpu_interrupt && _fifo_count < _packet_size ) {
      return;
   }

   _mpu_interrupt = false;
   _mpu_interrup_status = _mpu.getIntStatus();
   _fifo_count = _mpu.getFIFOCount();

   if( (_mpu_interrup_status & 0x10) || _fifo_count == 1024) {
      _mpu.resetFIFO();    //should never happen, unless our code is too inefficient
   } else if( _mpu_interrup_status & 0x02 ) {
      while( _fifo_count < _packet_size ) _fifo_count = _mpu.getFIFOCount();

      _mpu.getFIFOBytes(_fifo_buffer, _packet_size);
      _fifo_count -= _packet_size;
   }

}

Gyro::Gyro(Eventdispatcher *eventdispatcher) {
   this->_eventdispatcher = eventdispatcher;

   this->_orientation.w = 0;
   this->_orientation.x = 0;
   this->_orientation.y = 0;
   this->_orientation.z = 0;

   this->_acceleration.x = 0;
   this->_acceleration.y = 0;
   this->_acceleration.z = 0;

   _mpu_interrupt = false;

   _setup();

   Event *readValuesEvt = new ReadGyroValuesEvent(this);
   this->_eventdispatcher->always_exec(readValuesEvt);
}

bool Gyro::_setup() {
   Wire.begin();
   TWBR = 24;

   _mpu.initialize();
   if( !_mpu.testConnection() ) {
      return false;
   }

   _mpu.setXGyroOffset(X_GYRO_OFFSET);
   _mpu.setYGyroOffset(Y_GYRO_OFFSET);
   _mpu.setZGyroOffset(Z_GYRO_OFFSET);
   _mpu.setZAccelOffset(Z_ACCEL_OFFSET);

   _mpu_interrup_status = _mpu.getIntStatus();
   return true;
}


orientation_t* Gyro::get_orientation() {
   return &this->_orientation;
}

void Gyro::set_orientation(long w, long x, long y, long z) {
   this->_orientation.w = w;
   this->_orientation.x = x;
   this->_orientation.y = y;
   this->_orientation.z = z;
}

acceleration_t* Gyro::get_acceleration() {
   return &this->_acceleration;
}

Gyro::~Gyro() {
   
}

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
   
//}

//Gyro::~Gyro() {
//}

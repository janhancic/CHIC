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
         this->_gyro->update_data();
         return KEEP;
      }
};

void Gyro::update_data() {
   while ( !_mpu_interrupt && _fifo_count < _packet_size );

   _mpu_interrupt = false;
   _mpu_interrupt_status = _mpu.getIntStatus();
   _fifo_count = _mpu.getFIFOCount();

   if( (_mpu_interrupt_status & 0x10) || _fifo_count == 1024) {
      _mpu.resetFIFO();    //should never happen, unless our code is too inefficient
      Serial.println("FIFO overflow");
   } else if( _mpu_interrupt_status & 0x02 ) {
      while( _fifo_count < _packet_size ) _fifo_count = _mpu.getFIFOCount();

      _mpu.getFIFOBytes(_fifo_buffer, _packet_size);
      _fifo_count -= _packet_size;


    //  ------ get the values out of the fifo buffer
    if (_fifo_buffer == 0) return; //<-- means error

    //int16_t qI[4];
    //qI[0] = ((_fifo_buffer[0] << 8) + _fifo_buffer[1]);
    //qI[1] = ((_fifo_buffer[4] << 8) + _fifo_buffer[5]);
    //qI[2] = ((_fifo_buffer[8] << 8) + _fifo_buffer[9]);
    //qI[3] = ((_fifo_buffer[12] << 8) + _fifo_buffer[13]);
    //Serial.println(qI[0]);
    //Serial.println(qI[1]);
    //Serial.println(qI[2]);
    //Serial.println(qI[2]);

    //_orientation.w = (float)qI[0] / 16384.0f;
    //_orientation.x = (float)qI[1] / 16384.0f;
    //_orientation.y = (float)qI[2] / 16384.0f;
    //_orientation.z = (float)qI[3] / 16384.0f;

    Serial.println("--");
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

   Event *readValuesEvt = new ReadGyroValuesEvent(this);
   this->_eventdispatcher->always_exec(readValuesEvt);
}

bool Gyro::setup() {
   Wire.begin();
   TWBR = 24;
   
   _mpu.initialize();  //TODO: that stuff is not working ... don't know why
   if( !_mpu.testConnection() ) {
      Serial.println("returning false no connection...");
      return false;
   }

   _mpu.setXGyroOffset(X_GYRO_OFFSET);
   _mpu.setYGyroOffset(Y_GYRO_OFFSET);
   _mpu.setZGyroOffset(Z_GYRO_OFFSET);
   _mpu.setZAccelOffset(Z_ACCEL_OFFSET);


   Serial.println("Getting interrupt status");
   _mpu_interrupt_status = _mpu.getIntStatus();
   Serial.println("Got interrupt status");
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
   //_mpu_interrupt_status = _mpu.getIntStatus();

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

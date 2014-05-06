#include "drone.h"

Drone::Drone(Eventdispatcher *eventdispatcher, Gyro *gyro, Motor *fl, Motor *fr, Motor *bl, Motor *br) {
   _eventdispatcher  = eventdispatcher;
   _gyro             = gyro;
   _motor_fl         = fl;
   _motor_fr         = fr;
   _motor_bl         = bl;
   _motor_br         = br;

   _orientation = NULL;
}

void Drone::start() {

   if( _gyro->setup() ) {
      _orientation = _gyro->get_orientation();
   }

   _motor_fl->start();
   _motor_fr->start();
   _motor_bl->start();
   _motor_br->start();
}

void Drone::update() {

   if (!_motor_fl->is_started()) {
      return;
   }

   Serial.print("orientation: w:");
   Serial.print(this->_orientation->w);
   Serial.print(" x:");
   Serial.print(this->_orientation->x);
   Serial.print(" y:");
   Serial.print(this->_orientation->y);
   Serial.print(" z:");
   Serial.println(this->_orientation->z);
}


void Drone::stop() {
}

Drone::~Drone() {
}

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
	Serial.begin(115200);
	Serial.println("ALL SYSTEMS OPERATIONAL! PROCEED WITH TERMINATION!!");

   if( _gyro->setup() ) {
      _orientation = _gyro->get_orientation();
   }
}

void Drone::update() {

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

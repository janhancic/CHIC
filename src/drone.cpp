#include "drone.h"

Drone::Drone(Eventdispatcher *eventdispatcher, Gyro *gyro, Motor *fl, Motor *fr, Motor *bl, Motor *br) {
   _eventdispatcher  = eventdispatcher;
   _gyro             = gyro;
   _motor_fl         = fl;
   _motor_fr         = fr;
   _motor_bl         = bl;
   _motor_br         = br;


   _orientation->w = 0;
   _orientation->x = 0;
   _orientation->y = 0;
   _orientation->z = 0;
}

void Drone::start() {
	// if (all_motors_armed() == false) {
	// } else {
	// }

	Serial.begin(115200);
	Serial.println("ALL SYSTEMS OPERATIONAL! PROCEED WITH TERMINATION!!");
}

void Drone::update() {
   if( _gyro ) {
      _orientation = _gyro->get_orientation();
   }

   Serial.print("orientation: x:");
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

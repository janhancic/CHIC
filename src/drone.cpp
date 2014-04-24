#include "drone.h"

Drone::Drone(Eventdispatcher *eventdispatcher, Gyro *gyro, Motor *fl, Motor *fr, Motor *bl, Motor *br) {
   _eventdispatcher  = eventdispatcher;
   _gyro             = gyro;
   _motor_fl         = fl;
   _motor_fr         = fr;
   _motor_bl         = bl;
   _motor_br         = br;
}

void Drone::start() {
	// if (all_motors_armed() == false) {
	// } else {
	// }

	Serial.begin(115200);
	while (!Serial);
	Serial.println("ALL SYSTEMS OPERATIONAL! PROCEED WITH TERMINATION!!");
}

void Drone::update() {
	this->_orientation = this->_gyro->get_orientation();

	Serial.println("--");
	Serial.print(this->_orientation->x);
	Serial.print(this->_orientation->y);
	Serial.print(this->_orientation->z);
}


void Drone::stop() {
}

Drone::~Drone() {
}

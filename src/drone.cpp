#include "drone.h"

#define _xDEBUG
#include "debug.h"

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
   PRINT_INIT(115200);
	PRINT("ALL SYSTEMS OPERATIONAL! PROCEED WITH TERMINATION!!");

   if( _gyro->setup() ) {
      _orientation = _gyro->get_orientation();
   }
}

void Drone::update() {
   PRINT("orientation: w: %f, x: %f, y: %f, z: %f", (double)_orientation->w, (double)_orientation->x, (double)_orientation->y, (double)_orientation->z);
}


void Drone::stop() {
}

Drone::~Drone() {
}

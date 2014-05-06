#include "WrapArduino.h"
#include "drone.h"
#include "gyro.h"
#include "motor.h"

#define MOTOR1_PIN 3
#define MOTOR2_PIN 5
#define MOTOR3_PIN 6
#define MOTOR4_PIN 9
#define MOTOR1_IDLE_SPEED 50 
#define MOTOR2_IDLE_SPEED 50 
#define MOTOR3_IDLE_SPEED 50
#define MOTOR4_IDLE_SPEED 50

Drone             *drone;
Eventdispatcher    eventdispatcher;



void setup() {
   
   Serial.begin(115200);
   Serial.println("ALL SYSTEMS OPERATIONAL! PROCEED WITH TERMINATION!!");
  
   Gyro  *gyro = new Gyro(&eventdispatcher);
   Motor *fl = new Motor(&eventdispatcher, MOTOR1_PIN, MOTOR1_IDLE_SPEED);
   Motor *fr = new Motor(&eventdispatcher, MOTOR2_PIN, MOTOR2_IDLE_SPEED);
   Motor *bl = new Motor(&eventdispatcher, MOTOR3_PIN, MOTOR3_IDLE_SPEED);
   Motor *br = new Motor(&eventdispatcher, MOTOR4_PIN, MOTOR4_IDLE_SPEED);

   drone = new Drone(&eventdispatcher, gyro, fl, fr, bl, br);
   drone->start();
}

void loop() {
	eventdispatcher.loop();

	drone->update();
}

int main() {
   init();
   setup();

   while(1) loop();

   return 0;
}

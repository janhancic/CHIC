#include "WrapArduino.h"
#include "drone.h"

#define MOTOR1_PIN 3
#define MOTOR2_PIN 5
#define MOTOR3_PIN 6
#define MOTOR4_PIN 9
#define MOTOR1_IDLE_SPEED 100
#define MOTOR2_IDLE_SPEED 100
#define MOTOR3_IDLE_SPEED 100
#define MOTOR4_IDLE_SPEED 100

Drone drone;

void setup() {
   drone.start();
}

void loop() {

   drone.loop();
}


int main() {
   init();
   setup();

   while(1) loop();

   return 0;
}

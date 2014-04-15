#include <WrapArduino.h>
#include "motor.h"

#define MOTOR1_PIN 3
#define MOTOR2_PIN 5
#define MOTOR3_PIN 6
#define MOTOR4_PIN 9
#define MOTOR1_IDLE_SPEED 100
#define MOTOR2_IDLE_SPEED 100
#define MOTOR3_IDLE_SPEED 100
#define MOTOR4_IDLE_SPEED 100

Motor *motor1;
Motor *motor2;
Motor *motor3;
Motor *motor4;

void setup() {
   pinMode(13, OUTPUT);   
   digitalWrite(13, LOW);
   motor1 = new Motor(MOTOR1_PIN, MOTOR1_IDLE_SPEED);
   motor2 = new Motor(MOTOR2_PIN, MOTOR2_IDLE_SPEED);
   motor3 = new Motor(MOTOR3_PIN, MOTOR3_IDLE_SPEED);
   motor4 = new Motor(MOTOR4_PIN, MOTOR4_IDLE_SPEED);
}

void loop() {

   motor1->start();
   motor2->start();
   motor3->start();
   motor4->start();
}


int main() {
   init();
   setup();

   while(1) loop();

   return 0;
}

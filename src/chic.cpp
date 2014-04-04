#include <WrapArduino.h>
#include "motor.h"

#define MOTOR1_PIN 9
#define MOTOR2_PIN 11
#define MOTOR1_IDLE_SPEED 60
#define MOTOR2_IDLE_SPEED 60

Motor *motor1;
Motor *motor2;
int armed = 0;

void setup() {
   pinMode(13, OUTPUT);   
   digitalWrite(13, LOW);
   motor1 = new Motor(MOTOR1_PIN, MOTOR1_IDLE_SPEED);
   motor2 = new Motor(MOTOR2_PIN, MOTOR2_IDLE_SPEED);
   motor1->start();
   motor2->start();
}

void loop() {
   motor1->set_speed(80);
   motor2->set_speed(80);
}


int main() {
   init();
   setup();

   while(1) loop();

   return 0;
}

#include <Arduino.h>
#include "motor.cpp"

#define MOTOR1_PIN 9
#define MOTOR1_IDLE_SPEED 60

Motor *motor1;
int armed = 0;

void setup() {
   pinMode(13, OUTPUT);   
   digitalWrite(13, LOW);
   motor1 = new Motor(MOTOR1_PIN, MOTOR1_IDLE_SPEED);
   motor1->start();
}

void loop() {
   motor1->set_speed(80);

   //speed = motor1->get_speed(); 

   //if ( speed < 80 ) {
      //motor1->set_speed(speed + 10);
   //}

   //motor1->set_speed(80);
   
  // delay(1000);
}


int main() {
   init();
   setup();

   while(1) loop();

   return 0;
}

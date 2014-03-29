#include <Arduino.h>
#include "HardwareSerial.h"
#include <Servo.h>


Servo myServo;

void setup()   {
   Serial.begin(9600); 
   pinMode(13, OUTPUT);
   myServo.attach(9);

}

// the loop() method runs over and over again,
// as long as the Arduino has power

void loop()
{
   Serial.println("Hello World");
   digitalWrite(13, HIGH);
   //myServo.write(20);
   delay(1000);   
   digitalWrite(13, LOW);
   //myServo.write(150);
   delay(1000);
}

int main() {
	init();
	setup();

	while(1) loop();

	return 0;

}

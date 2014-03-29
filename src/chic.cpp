#include <Arduino.h>
#include <HardwareSerial.h>


void setup()   {
   Serial.begin(9600); 
   pinMode(13, OUTPUT);
}

// the loop() method runs over and over again,
// as long as the Arduino has power

void loop()
{
   Serial.println("Hello World");
   digitalWrite(13, HIGH);
   delay(1000);   
   digitalWrite(13, LOW);
   delay(1000);
}

int main() {
	init();
	setup();

	while(1) loop();

	return 0;

}

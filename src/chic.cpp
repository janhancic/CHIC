#include <Arduino.h>
#include <HardwareSerial.h>


void setup()   {
   Serial.begin(9600); 
}

// the loop() method runs over and over again,
// as long as the Arduino has power

void loop()
{
   Serial.println("Hello World");
   delay(1000);   
}

int main() {
	init();
	setup();

	while(1) loop();

	return 0;

}

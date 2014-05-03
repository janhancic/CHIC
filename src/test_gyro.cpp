#define CATCH_CONFIG_MAIN  
#include "catch.hpp"
#include "gyro.cpp"

//TODO: functions should be mocks?
void delay(int time) {
}

void Servo::attach(int pin) {
}

void Servo::write(int pos) {
}

long millis() {
   return 10;
}

void digitalWrite(int pin, int high) {
}

TEST_CASE( "", "[set_speed]" ) {
}


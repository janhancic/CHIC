#define CATCH_CONFIG_MAIN  
#include "catch.hpp"
#include "motor.h"


//TODO: functions should be mocks?
void delay(int time) {
}

void Servo::attach(int pin) {
}

void Servo::write(int pos) {
}

Motor motor = Motor::Motor(1, 10);

TEST_CASE( "motor set_speed sets speed", "[set_speed]" ) {
   motor.set_speed(100);
   REQUIRE( motor.get_speed() == 100 );
}


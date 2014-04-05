#define CATCH_CONFIG_MAIN  
#include "catch.hpp"
#include "myClass.h"

void pinMode(int pin, int mode) {
}

void digitalWrite(int pin, int val) {
}

MyClass led = MyClass::MyClass(1);

TEST_CASE( "toggle sets light to on", "[toggle led]" ) {
   led.toggle();
   REQUIRE( led.isOn() == true );
}


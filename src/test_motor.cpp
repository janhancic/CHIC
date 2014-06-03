#define CATCH_CONFIG_RUNNER
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#undef FAIL
#undef SUCCEED
#include "catch.hpp"
#include "motor.h"
using testing::InitGoogleMock;
using ::testing::_;
#include "MockEventdispatcher.h"

#define _IDLE_SPEED 50

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

Motor *motor = new Motor(NULL, 1, _IDLE_SPEED);

TEST_CASE( "Motor constructor sets required fields", "[initialization]" ) {
   REQUIRE( motor->is_started() == false );
   REQUIRE( motor->get_speed() == 0 );
}

TEST_CASE( "motor set_speed ", "[set speed]" ) {

   SECTION( "set valid speeds" ) {
      motor->set_speed(100);
      REQUIRE( motor->get_speed() == 100 );
   }
   SECTION( "set invalid speeds" ) {
      motor->set_speed( -10 );
      REQUIRE( motor->get_speed() == 100 );

      motor->set_speed( 200 );
      REQUIRE( motor->get_speed() == 100 );
   }
}

TEST_CASE( "start arms the motor", "[arming routine]") {
   MockEventdispatcher mockEventdispatcher;
   motor = new Motor(&mockEventdispatcher, 1, _IDLE_SPEED);

   EXPECT_CALL(mockEventdispatcher, schedule(2000, _)).Times(1);
   motor->start();

   SECTION( "arming event given an eventdispatcher schedules speedup event" ) {
      ArmMotorsEvent *armEvent = new ArmMotorsEvent(&mockEventdispatcher, motor);

      EXPECT_CALL(mockEventdispatcher, schedule(50, _));
      REQUIRE( armEvent->fire_event() == CLEAR );
   }

   SECTION (" arming event without eventdispatcher remains scheduled until idle speed is reached" ) {
      ArmMotorsEvent *armEvent = new ArmMotorsEvent(NULL, motor);

      REQUIRE( armEvent->fire_event() == KEEP );
      REQUIRE( motor->is_started() == false );

      motor->set_speed(_IDLE_SPEED);
      REQUIRE( armEvent->fire_event() == CLEAR );
      REQUIRE( motor->is_started() == true );
   }
}


int main( int argc, char* argv[] )
{
   ::testing::GTEST_FLAG(throw_on_failure) = true;
   ::testing::InitGoogleMock(&argc, argv); 

   int result = Catch::Session().run( argc, argv );

   return result;
}

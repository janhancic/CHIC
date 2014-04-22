#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "eventdispatcher.h"

long millis() {
   struct timeval tv;
   gettimeofday(&tv, NULL);
   return ((tv.tv_sec) * 1000 + tv.tv_usec/1000.0) + 0.5;
}

class TestEvent : public Event {
   private:
      long  *_fire_time;

   public:
      TestEvent(long *fire_time) {
         this->_fire_time = fire_time;
      }
   
      EventEnum fire_event() {
         *_fire_time = millis();
         return CLEAR;
      }
};

TEST_CASE( "schedule always_exec event and see that it gets triggered", "[basic always exec]" ) {
   Eventdispatcher dispatcher = Eventdispatcher(); 

   long ev1_time = -1;
   long cmp_time = -1;
   TestEvent *ev = new TestEvent(&ev1_time);

   dispatcher.always_exec(ev);
   REQUIRE( ev1_time == -1 );

   cmp_time = millis();
   usleep(10 * 1000); //wait before firing event, to make sure we'll get different timestamp
   dispatcher.loop();

   REQUIRE( ev1_time > cmp_time );

   usleep(10 * 1000); //wait before firing event, to make sure we'll get different timestamp
   cmp_time = millis();
   dispatcher.loop();

   REQUIRE( ev1_time < cmp_time );
}

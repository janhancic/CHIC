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
   ev1_time = -1;

   cmp_time = millis();
   dispatcher.loop();

   REQUIRE( ev1_time == -1 );
}

#define NUM_EVENTS 20
TEST_CASE( "schedule multiple always_exec events and see they get triggered", "[advanced always exed]") {
   Eventdispatcher dispatcher = Eventdispatcher();
   long   cmp_time = -1;
   long   fire_times[NUM_EVENTS];
   Event *events[NUM_EVENTS];

   for(int i = 0; i < NUM_EVENTS; i++) {
      fire_times[i] = -1;
      events[i] = new TestEvent(fire_times + i);
      dispatcher.always_exec(events[i]);
   }

   cmp_time = millis();
   usleep(10 * 1000);
   dispatcher.loop();

   for(int i = 0; i < NUM_EVENTS; i++) {
      REQUIRE( fire_times[i] > cmp_time );
      fire_times[i] = -1;
   } 

   dispatcher.loop();

   for(int i = 0; i < NUM_EVENTS; i++) {
      REQUIRE( fire_times[i] == -1 );
   } 
}

#define TIMEOUT 500
#define LOOP_SLEEP 10
TEST_CASE( "schedule delayed events", "[scheduling]" ) {
   Eventdispatcher dispatcher = Eventdispatcher();
   long     cmp_time1 = -1;
   long     cmp_time2 = -1;
   long     ev_time = -1;
   Event   *event = new TestEvent(&ev_time); 

   cmp_time1 = millis();
   dispatcher.schedule((long)TIMEOUT, event);
   cmp_time2 = millis();


   while( ev_time == -1 && cmp_time2 + TIMEOUT + LOOP_SLEEP*5 >= millis() ) {
      usleep(LOOP_SLEEP * 1000);
      dispatcher.loop();
   }

   REQUIRE( (cmp_time1 + TIMEOUT) <= ev_time );
   REQUIRE( ev_time <= (cmp_time2 + TIMEOUT + LOOP_SLEEP + 10 /* processing time */) );
}

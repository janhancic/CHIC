#include "WrapArduino.h"

#ifndef __eventdispatcher_h
#define __eventdispatcher_h

class Event {
   public:
      virtual void fire_event(); 
};

class Eventdispatcher {
   private:

      class InternalEvent {
         public:
            InternalEvent(long when_millis, Event *event);
            long  when_millis;
            Event *event;
      };


      InternalEvent **_always_exec;
      InternalEvent **_event_heap;

   public:
      Eventdispatcher();

      void set_timeout(long timeout, Event *event);
      void always_exec(Event *event);
      void clear_timeout(Event *event);
      void loop();

      ~Eventdispatcher();
};


#endif

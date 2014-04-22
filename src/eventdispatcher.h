#include "WrapArduino.h"
#include "arrayset.h"

#ifndef __eventdispatcher_h
#define __eventdispatcher_h

enum EventEnum { CLEAR, KEEP };

class Event {
   public:
      virtual EventEnum fire_event() = 0; 
};

class Eventdispatcher {
   private:
      class           InternalEvent;
      ArraySet       *_always_exec;
      InternalEvent **_event_heap;

   public:
      Eventdispatcher();

      void set_timeout(long timeout, Event *event);
      void always_exec(Event *event);
      void clear_timeout(Event *event);
      void loop();

      ~Eventdispatcher();
};

class Eventdispatcher::InternalEvent {
   private:
      long      _timeout;
      long      _when;

   public:
      InternalEvent(long timeout, Event *event);
      Event    *event;
};


#endif

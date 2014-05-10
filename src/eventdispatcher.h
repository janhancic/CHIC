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
      ArraySet       *_event_set;

   public:
      Eventdispatcher();

      virtual void schedule(long timeout, Event *event);
      virtual void always_exec(Event *event);
      virtual void loop();

      ~Eventdispatcher();
};

class Eventdispatcher::InternalEvent : public Event {
   private:
      long      _timeout;
      long      _when;
      Event    *_event;

   public:
      InternalEvent(long timeout, Event *event);
      Event*      get_event();
      bool        is_due();
      EventEnum   fire_event();

      ~InternalEvent();
};


#endif

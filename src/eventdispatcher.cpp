#include "eventdispatcher.h"
#include "WrapArduino.h"

#define HEAP_SIZE 50;

// InternalEvent implementation


InternalEvent::InternalEvent(long when_millis, Event *event) {
   this->when_millis = when_millis;
   this->event       = event;
}

// Eventdispatcher implementation

Eventdispatcher::Eventdispatcher() {
   this->_always_exec = (InternalEvent**)calloc(HEAP_SIZE * sizeof(InternalEvent*));
   this->_event_heap  = (InternalEvent**)calloc(HEAP_SIZE * sizeof(InternalEvent*));
};

void Eventdispatcher::set_timeout(long timeout, Event *event) {
   InternalEvent *evnt = new InternalEvent(millis() + timeout, event);

   for (int i = 0; i < HEAP_SIZE; i++) {
      if (this->_event_heap[i] == NULL) {
         break;
      } 
   }
};

void Eventdispatcher::set_interval(long interval, Event *event) {
};

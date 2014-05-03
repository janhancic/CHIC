#include "eventdispatcher.h"
#include "WrapArduino.h"

#define ALWAYS_EXEC_SIZE 20

Eventdispatcher::InternalEvent::InternalEvent(long timeout, Event *event) {
   this->_timeout     = timeout;
   this->_when        = millis() + timeout;
   this->_event       = event;
};

Event* Eventdispatcher::InternalEvent::get_event() {
   return _event;
}

bool Eventdispatcher::InternalEvent::is_due() {
   return millis() >= _when; 
}

EventEnum Eventdispatcher::InternalEvent::fire_event() {
   return _event->fire_event();
}

Eventdispatcher::InternalEvent::~InternalEvent() {
   free(_event);
}

Eventdispatcher::Eventdispatcher() {
   this->_always_exec = new ArraySet(ALWAYS_EXEC_SIZE); 
   this->_event_set   = new ArraySet(ALWAYS_EXEC_SIZE); 
};

void Eventdispatcher::always_exec(Event *ev) {
   _always_exec->add(ev);
};

void Eventdispatcher::schedule(long timeout, Event *event) {
   InternalEvent *evnt = new InternalEvent(timeout, event);
   _event_set->add(evnt);
};

void Eventdispatcher::loop() {
   Event          *ev    = NULL; 
   InternalEvent  *intEv = NULL;

   for( int i = 0; i < _always_exec->count(); i++ ) {
      ev = (Event*)_always_exec->get(i);

      if( ev->fire_event() == CLEAR ) {
         _always_exec->remove(ev);
         free(ev);
         i--; //TODO: current way is impl dependent, make it more independent 
      }
   }

   for( int i = 0; i < _event_set->count(); i++ ) {
      intEv = (InternalEvent*)_event_set->get(i);

      if( intEv->is_due() ) {
         if( intEv->fire_event() == CLEAR ) {
            _event_set->remove(intEv);
            free(intEv);
            i--; //TODO: current way is impl dependent, make it more independent 
         }
      }
   }
};

Eventdispatcher::~Eventdispatcher() {
   free(_always_exec);
   free(_event_set);
}

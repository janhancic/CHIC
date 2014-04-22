#include "eventdispatcher.h"
#include "WrapArduino.h"

#define ALWAYS_EXEC_SIZE 20

Eventdispatcher::InternalEvent::InternalEvent(long timeout, Event *event) {
   this->_timeout     = timeout;
   this->_when        = millis() + timeout;
   this->event        = event;
};

Eventdispatcher::Eventdispatcher() {
   this->_always_exec = new ArraySet(ALWAYS_EXEC_SIZE); 
   this->_event_heap  = NULL; 
};

void Eventdispatcher::always_exec(Event *ev) {
   _always_exec->add(ev);
};

void Eventdispatcher::set_timeout(long timeout, Event *event) {
   //InternalEvent *evnt = new InternalEvent(millis() + timeout, event);

   //for (int i = 0; i < HEAP_SIZE; i++) {
      //if (this->_event_heap[i] == NULL) {
         //break;
      //} 
   //}
};

void Eventdispatcher::loop() {
   Event *ev = NULL; 

   for( int i = 0; i < _always_exec->count(); i++ ) {
      ev = (Event*)_always_exec->get(i);

      if( ev->fire_event() == CLEAR ) {
         _always_exec->remove(ev);
         free(ev);
      }
   }

};

Eventdispatcher::~Eventdispatcher() {
   free(_always_exec);
}

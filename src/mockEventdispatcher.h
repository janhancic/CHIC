#include "eventdispatcher.h"

class MockEventdispatcher : public Eventdispatcher {
   public:
      MOCK_METHOD2(schedule, void(long, Event*));
      MOCK_METHOD1(always_exec, void(Event*));
      MOCK_METHOD1(exec, void(Event*));
};

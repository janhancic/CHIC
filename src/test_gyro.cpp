#define CATCH_CONFIG_MAIN  
#include "gmock/gmock.h"
#undef FAIL
#undef SUCCEED
#include "catch.hpp"
//#include "gyro.cpp"


class Test {
   public:
      void initialize() {
         printf("not mocked initialize\n");
      }

      bool testConnection() {
         printf("non-mocked testConnection\n");
         return true;
      }
};

class MockMPU: public Test {
 public:
  MOCK_METHOD0(initialize, void());
  MOCK_METHOD0(testConnection, bool());
  //MOCK_METHOD1(Forward, void(int distance));
  //MOCK_METHOD1(Turn, void(int degrees));
  //MOCK_METHOD2(GoTo, void(int x, int y));
  //MOCK_CONST_METHOD0(GetX, int());
  //MOCK_CONST_METHOD0(GetY, int());
};

//TODO: functions should be mocks?
void delay(int time) {
}

void digitalWrite(int pin, int high) {
}

TEST_CASE( "", "[basic?]" ) {
   ::testing::GTEST_FLAG(throw_on_failure) = true;
   ::testing::InitGoogleMock((int)0,(char**)NULL); 

   MockMPU mpu;
   
   EXPECT_CALL(mpu, method(initialize))
    .Times(1)
}


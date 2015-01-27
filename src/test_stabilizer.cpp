#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "WrapArduino.h"
#include "stabilizer.cpp"

long millis() {
   struct timeval tv;
   gettimeofday(&tv, NULL);
   return ((tv.tv_sec) * 1000 + tv.tv_usec/1000.0) + 0.5;
}

orientation_t base_orientation;
Stabilizer *stabilizer = new Stabilizer(&base_orientation);


TEST_CASE( "drone initialize does something", "[initialization]" ) {
   stabilizer->calculateAdjustments();
}

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "arrayset.h"

TEST_CASE( "adding and removing elements", "[basic]" ) {
   ArraySet set = ArraySet();

   REQUIRE( set.size() == 10 );
   REQUIRE( set.count() == 0 );

   SECTION( "add an element" ) {
      int val = 10;

      set.add(&val);

      REQUIRE( set.size() == 10 );
      REQUIRE( set.count() == 1 );

      SECTION( "add one more" ) {
         int val1 = 15;
         set.add(&val1);

         REQUIRE( set.size() == 10 );
         REQUIRE( set.count() == 2 );

         SECTION( "remove one element" ) {
            set.remove(&val);

            REQUIRE( set.size() == 10 );
            REQUIRE( set.count() == 1);
         }

         SECTION( "remove all elements" ) {
            set.remove(&val);
            set.remove(&val1);

            REQUIRE( set.size() == 10 );
            REQUIRE( set.count() == 0);
         }
      }
   }
}

TEST_CASE( "adding more elments than space resizes", "[resize]" ) {
   ArraySet set = ArraySet(1);

   REQUIRE( set.size() == 1 );
   REQUIRE( set.count() == 0 );

   SECTION( "add more elements than space" ) {
      int val1 = 10;
      int val2 = 20;

      set.add(&val1);
      set.add(&val2);

      REQUIRE( set.size() == 2 );
      REQUIRE( set.count() == 2 );

      SECTION( "add even more" ) {
         int val3 = 30;

         set.add(&val3);

         REQUIRE( set.size() == 4 );
         REQUIRE( set.count() == 3);
      }
   }
}


TEST_CASE( "add, get and delete", "[random]" ) {
   ArraySet set = ArraySet();

   SECTION( "add two and remove one element" ) {
      int val = 10;
      int val1 = 15;

      set.add(&val);
      set.add(&val1);

      REQUIRE( set.count() == 2 );
      REQUIRE( set.get(0) == &val );
      REQUIRE( set.get(1) == &val1 );


      set.remove(&val);
      REQUIRE( set.count() == 1);
      REQUIRE( set.get(0) == &val1);
   }
}

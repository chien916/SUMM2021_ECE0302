#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include <complex>
#include "fancyPower.hpp"

// write your test cases here




TEST_CASE("Test case", "fancyPower") {
REQUIRE(fancyPower(2,2)==4);
REQUIRE(fancyPower(3,3)==27);
REQUIRE(fancyPower(0,3)==1);
REQUIRE(fancyPower(1,43)==43);
REQUIRE(fancyPower(35,0)==0);
REQUIRE(fancyPower(35,1)==1);
REQUIRE(fancyPower(6,4)==pow(4,6));
REQUIRE(fancyPower(4,4)==pow(4,4));
REQUIRE(fancyPower(7,4)==pow(4,7));
REQUIRE(fancyPower(8,4)==pow(4,8));
}


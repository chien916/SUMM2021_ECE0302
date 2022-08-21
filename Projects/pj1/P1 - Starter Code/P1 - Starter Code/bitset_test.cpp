#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE

#include "catch.hpp"

#include "bitset.hpp"

// THIS IS JUST AN EXAMPLE
// There should be at least one test per Bitset method

TEST_CASE("Test bitset construction", "[bitset]") {

    Bitset normal0;
    REQUIRE(normal0.size() == 8);
    REQUIRE(normal0.good());
    normal0.set(0);
    REQUIRE(normal0.test(0) == 1);
    normal0.toggle(1);
    REQUIRE(normal0.asString() == "11000000");
    Bitset normal1("1010");
    REQUIRE(normal1.asString() == "1010");
    normal1.reset(0);
	REQUIRE(normal1.asString() == "0010");
    Bitset normal2(7);
    REQUIRE(normal2.asString() == "0000000");
    Bitset weird0(-4);
    REQUIRE(weird0.good() == false);
    Bitset weird1("does not contain int");
    REQUIRE(weird1.good() == false);
}


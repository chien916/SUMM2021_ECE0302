#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "dynamic_bag.hpp"

// force template expansion for ints
template
class DynamicBag<int>;

TEST_CASE("Calling all public members", "[DynamicBag]") {
    DynamicBag<int> b;
    DynamicBag<int> b2;
    //b.add(0);---
    //b.remove(0);---
    //b.isEmpty();---
    //b.getCurrentSize();---
    //b.clear();---
    //b.getFrequencyOf(0);---
    //b.contains(0);---
    REQUIRE(b.isEmpty() == 1);
    b.add(88);
    b.add(88);
    b.add(88);
    b.add(88);
    b.add(88);
    b.remove(88);
    b.add(3);
    REQUIRE(b.isEmpty() == 0);
    REQUIRE(b.getFrequencyOf(88) == 4);
    REQUIRE(b.getFrequencyOf(3) == 1);
    REQUIRE(b.getFrequencyOf(38) == 0);
    REQUIRE(b.contains(88)==1);
    REQUIRE(b.contains(888)==0);
    REQUIRE(b.getCurrentSize()==5);

    b2.operator=(b);
    REQUIRE(b2.getFrequencyOf(88) == 4);
    REQUIRE(b2.getFrequencyOf(3) == 1);
    REQUIRE(b2.getFrequencyOf(38) == 0);

    b.clear();
    REQUIRE(b.isEmpty() == 1);

    DynamicBag<int> b3(b2);
    REQUIRE(b3.getFrequencyOf(88) == 4);
    REQUIRE(b3.getFrequencyOf(3) == 1);
    REQUIRE(b3.getFrequencyOf(38) == 0);
}

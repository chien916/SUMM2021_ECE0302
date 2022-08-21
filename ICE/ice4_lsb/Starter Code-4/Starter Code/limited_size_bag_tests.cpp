#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "limited_size_bag.hpp"

// force template expansion for ints
template
class LimitedSizeBag<int>;

TEST_CASE("Empty Test", "[LimitedSizeBag]") {
    LimitedSizeBag<int> b;
    LimitedSizeBag<int> b2;

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
    REQUIRE(b.remove(231)==0);

    b2.operator=(b);
    REQUIRE(b2.getFrequencyOf(88) == 4);
    REQUIRE(b2.getFrequencyOf(3) == 1);
    REQUIRE(b2.getFrequencyOf(38) == 0);
    REQUIRE(b.getCurrentSize()==5);

    b.clear();
    REQUIRE(b.isEmpty() == 1);

    LimitedSizeBag<int> b3(b2);
    REQUIRE(b3.getFrequencyOf(88) == 4);
    REQUIRE(b3.getFrequencyOf(3) == 1);
    REQUIRE(b3.getFrequencyOf(38) == 0);

    LimitedSizeBag<int> b4;
    b4.add(100);
    b4.add(100);
    b4.add(100);
    b4.add(100);
    b4.add(100);
    b4.add(100);
    b4.add(100);
    b4.add(100);
    b4.add(100);
    b4.add(100);
    REQUIRE(b4.getFrequencyOf(100) == 10);
    REQUIRE(b4.add(100) == 0);//test exceeding capacity overflows
}

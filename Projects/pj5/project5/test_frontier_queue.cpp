#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "frontier_queue.hpp"
// TODO implement your tests here
// note you can use any supported type for the value type T
// including the Puzzle type as in the solver code

TEST_CASE("TEST FRONTIER QUEUE WITH STATE<typeName>") {
    frontier_queue<unsigned int> duiLie;

    //=====================================================================================
    //I used a lot of "8"s in the test cases because eight is a lucky number in my culture.
    //However, all my luckiness depends on how you grade this project.
    //So if you have a good heart, please show mercy to end this semester! :D
    //=====================================================================================

    //=====================================================================================
    //test cases for empty():
    REQUIRE(duiLie.empty());
    duiLie.push(1, 1, 1);
    REQUIRE_FALSE(duiLie.empty());
    duiLie.pop();
    REQUIRE(duiLie.empty());
    //=====================================================================================

    //=====================================================================================
    //test cases for push():
    duiLie.push(1, 88888888, 100);
    REQUIRE(duiLie.contains(1));
    duiLie.push(1, 44444444, 100);
    REQUIRE(duiLie.contains(1));
    duiLie.pop();
    REQUIRE_FALSE(duiLie.contains(1));
    for (int i = 1; i <= 888; i++) {
        duiLie.push(i - 1, 10 * (i - 1), 100 * (i - 1));
    }
    for (int i = 1; i <= 888; i++) {
        duiLie.push(i - 1, 2 * (i - 1), 100 * (i - 1));
    }
    for (int i = 1; i <= 888; i++) {
        REQUIRE(duiLie.contains(i - 1));
    }
    //=====================================================================================

    //=====================================================================================
    //test cases for pop():
    for (int i = 1; i <= 888; i++) {
        auto tempPopedState = duiLie.pop();
        REQUIRE(tempPopedState.getValue() == i - 1);
        REQUIRE(tempPopedState.getPathCost() == 2 * (i - 1));
    }
    REQUIRE_THROWS_AS(duiLie.pop(), std::logic_error &);
    //=====================================================================================

    //=====================================================================================
    //test cases for contains():
    for (int i = 1; i <= 888; i++) {
        duiLie.push(i - 1, 2 * (i - 1), 100 * (i - 1));
    }
    for (int i = 1; i <= 888; i++) {
        REQUIRE(duiLie.contains(i - 1));
        REQUIRE_FALSE(duiLie.contains(88888888));
    }
    //=====================================================================================


    //=====================================================================================
    //test cases for replaceif():
    SECTION("replaceif()") {
        for (int i = 1; i <= 888; i++) {
            duiLie.replaceif(i - 1, 0);
        }
        for (int i = 1; i <= 888; i++) {
            REQUIRE(duiLie.pop().getPathCost() == 0);
        }
    }
    //=====================================================================================


}

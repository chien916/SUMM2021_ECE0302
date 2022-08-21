#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE

#include "catch.hpp"
#include "FindPalindrome.hpp"

// There should be at least one test per FindPalindrome method

TEST_CASE("Test FindPalindrome add a non-allowable word", "[FindPalindrome]") {
    INFO("Hint: add a single non-allowable word");
    FindPalindrome b;
    REQUIRE(!b.add("kayak1"));
    b.clear();
    REQUIRE(b.add("WAS"));
    REQUIRE(b.add("it"));
    REQUIRE(b.add("A"));
    REQUIRE(b.add("rAt"));
    REQUIRE(b.add("I"));
    REQUIRE(b.add("saw"));
    REQUIRE(b.number()==2);
    std::vector<std::string> test1;
    test1.push_back("abcba");
    REQUIRE(b.cutTest1(test1)==1);
    test1.push_back("l");
    REQUIRE(b.cutTest1(test1)==0);
    std::vector<std::string> test2;
    test2.push_back("abc");
    REQUIRE(b.cutTest2(test2,test1)==1);
    test2.push_back("abckkk");
    REQUIRE(b.cutTest2(test2,test1)==0);
}


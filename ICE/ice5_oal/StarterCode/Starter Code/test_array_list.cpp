#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "array_list.hpp"

//force class expansion
template
class ArrayList<int>;

TEST_CASE("Test", "[ArrayList]") {

    ArrayList<int> list;
    list.clear();
    REQUIRE(list.isEmpty()==1);
    list.insert(10);
    list.insert(5);
    list.insert(15);
    list.insert(1);
    REQUIRE(list.getEntry(1)==1);
    REQUIRE(list.getEntry(2)==5);
    REQUIRE(list.isEmpty()==0);
    REQUIRE(list.getLength()==4);
    list.remove(1);
    list.setEntry(1,7);
    REQUIRE(list.getEntry(1)==7);
}

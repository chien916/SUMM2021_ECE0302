#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "linked_list.hpp"
#include <complex>

template
class LinkedList<int>;

TEST_CASE("TODO", "[LinkedList]") {
    LinkedList<int> testList;
    int testInt = -1;
    REQUIRE(testList.getLength() == 0);//unitialized list should be of length 0
    REQUIRE(testList.isEmpty() == true);//unitialized list should be of length 0
    REQUIRE(testList.insert(100,testInt)==false);//out of bound test
    REQUIRE(testList.remove(50)==false);//out of bound test
    REQUIRE(testList.getLength() == 0);//unitialized list should be of length 0
    REQUIRE(testList.insert(1,2)==true);//insert in the beginning
    REQUIRE(testList.getLength() == 1);//it should be [2] of length 1
    REQUIRE(testList.getEntry(1) == 2);//it should be [2]
    REQUIRE(testList.insert(2,8)==true);//insert in the end
    REQUIRE(testList.insert(1,4)==true);//insert in the middle
    REQUIRE(testList.getEntry(1) == 4);//it should be [4,2,8]
    REQUIRE(testList.getEntry(2) == 2);//it should be [4,2,8]
    REQUIRE(testList.getEntry(3) == 8);//it should be [4,2,8]
    REQUIRE(testList.getLength() == 3);//it should be [4,2,8] of length 3
    REQUIRE(testList.remove(2) == true);//remove 2 from list
    REQUIRE(testList.getEntry(2) == 8);//it should be [4,8]
    REQUIRE(testList.getLength() == 2);//it should be [4,8] of length 2
    std::cout<<*(testList.getPointer(1))).getItem();
    //LinkedList<int> testList2(testList);
    //REQUIRE(testList2.getEntry(2) == 8);//it should be [4,8]
    //REQUIRE(testList2.getLength() == 2);//it should be [4,8] of length 2
    //testList.clear();//test clearing function
    //REQUIRE(testList.isEmpty() == true);//cleared list should be of length 0

}

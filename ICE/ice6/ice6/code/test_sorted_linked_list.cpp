#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE

#include "catch.hpp"
#include "linked_list.hpp"
#include "sorted_linked_list.hpp"


TEST_CASE("Testing Pre-imported LinkedList") {
    //I did not test "LinkedList" in details since it's directly imported from previous ICE
    LinkedList<int> t1;
    t1.insert(1, 1);
    t1.insert(2, 3);
    t1.insert(3, 5);
    t1.insert(4, 7);
    REQUIRE(t1.getEntry(1) == 1);
    REQUIRE(t1.getEntry(2) == 3);
    REQUIRE(t1.getEntry(3) == 5);

}

typedef SortedLinkedList<char> ListType;

template
class SortedLinkedList<int>;

TEST_CASE("Testing isEmpty", "[sorted linked list]") {
    ListType lst;
    REQUIRE(lst.isEmpty());

    lst.insert('a');
    REQUIRE(!lst.isEmpty());

    lst.removeAt(0);
    REQUIRE(lst.isEmpty());
}

TEST_CASE("Testing getLength", "[sorted linked list]") {
    ListType lst;
    REQUIRE(lst.getLength() == 0);

    lst.insert('b');
    REQUIRE(lst.getLength() == 1);

    lst.insert('a');
    REQUIRE(lst.getLength() == 2);

    lst.removeAt(0);
    REQUIRE(lst.getLength() == 1);

    lst.removeAt(0);
    REQUIRE(lst.getLength() == 0);
}

TEST_CASE("Testing insert", "[sorted linked list]") {
    //I modified this test case a little bit so it can test if a certain element is inserted in the right position
    ListType lst;
    //Let's only insert a,c,e,g......
    char c = 'a';
    while (c <= 'z') {
        lst.insert(c);
        c = c + 2;
    }
    REQUIRE(lst.getLength() == 13);
    for (int i = 0; i < 13; i++) {
        char left = lst[i];
        char right = ('a' + 2 * i);
        REQUIRE(left == right);
    }
    //Let's then insert remaining letters and see if they are inserted into the appropriate place
    c = 'b';
    while (c <= 'z') {
        lst.insert(c);
        c = c + 2;
    }
    for (int i = 0; i < 26; i++) {
        char left = lst[i];
        char right = ('a' + 1 * i);
        REQUIRE(left == right);
    }
}

TEST_CASE("Testing remove", "[sorted linked list]") {
    //I don't see test case for remove function, so I added my own by modifying the last test case
    ListType lst;
    char c = 'a';
    while (c <= 'z') {
        lst.insert(c);
        c = c + 1;
    }
    REQUIRE(lst.getLength() == 26);
    //Remove b,d,f,h......
    c = 'b';
    while (c <= 'z') {
        lst.remove(c);
        c = c + 2;
    }
    for (int i = 0; i < 13; i++) {
        char left = lst[i];
        char right = ('a' + 2 * i);
        REQUIRE(left == right);
    }
}

TEST_CASE("Testing removeAt", "[sorted linked list]") {
    ListType lst;
    char c = 'a';
    while (c <= 'z') {
        lst.insert(c);
        ++c;
    }
    REQUIRE(lst.getLength() == 26);

    lst.removeAt(5);
    REQUIRE(lst.getLength() == 25);
    REQUIRE(lst[5] == 'g');

    lst.removeAt(11);
    REQUIRE(lst.getLength() == 24);
    REQUIRE(lst[11] == 'n');

    lst.removeAt(0);
    REQUIRE(lst.getLength() == 23);
    REQUIRE(lst[0] == 'b');

    lst.removeAt(22);
    REQUIRE(lst.getLength() == 22);
    REQUIRE(lst[21] == 'y');
}


TEST_CASE("Testing clear", "[sorted linked list]") {
    ListType lst;

    char c = 'a';
    while (c <= 'z') {
        lst.insert(c);
        ++c;
    }
    REQUIRE(lst.getLength() == 26);

    lst.clear();
    REQUIRE(lst.getLength() == 0);

    c = 'a';
    while (c <= 'j') {
        lst.insert(c);
        ++c;
    }
    REQUIRE(lst.getLength() == 10);

    ListType lst_empty;
    lst_empty.clear();
    REQUIRE(lst_empty.getLength() == 0);
}


TEST_CASE("Testing subscript overloading", "[sorted linked list]") {
    ListType lst;

    char c = 'a';
    while (c <= 'z') {
        lst.insert(c);
        ++c;
    }
    REQUIRE(lst.getLength() == 26);

    for (int i = 0; i < 26; ++i) {
        REQUIRE(lst[i] == 'a' + i);
    }
}

TEST_CASE("Testing copy", "[sorted linked list]") {
    ListType lst;
    auto i = 1;
    char c = 'a';
    while (c <= 'z') {
        lst.insert(c);
        ++c;
    }
    REQUIRE(lst.getLength() == 26);

    ListType lst_copy = lst;

    REQUIRE(lst_copy.getLength() == 26);

    for (int i = 0; i < 26; ++i) {
        REQUIRE(lst_copy[i] == lst[i]);
    }
}

TEST_CASE("Testing copy empty", "[sorted linked list]") {
    ListType lst;
    ListType lst_copy = lst;

    REQUIRE(lst.getLength() == 0);
    REQUIRE(lst_copy.getLength() == 0);
}

TEST_CASE("Testing assignment", "[sorted linked list]") {
    ListType lst;
    ListType lst_copy;

    char c = 'a';
    while (c <= 'z') {
        lst.insert(c);
        ++c;
    }
    REQUIRE(lst.getLength() == 26);

    lst_copy = lst;

    REQUIRE(lst_copy.getLength() == 26);

    for (int i = 0; i < 26; ++i) {
        REQUIRE(lst_copy[i] == lst[i]);
    }
}

TEST_CASE("Testing assignment to/from empty", "[sorted linked list]") {
    ListType lst;
    ListType lst_copy;

    lst_copy = lst;

    REQUIRE(lst.getLength() == 0);
    REQUIRE(lst_copy.getLength() == 0);
}

TEST_CASE("Testing exceptions", "[sorted linked list]") {
    ListType lst;

    CHECK_THROWS_AS(lst.removeAt(0), std::range_error);
    CHECK_THROWS_AS(lst[0], std::range_error);

    lst.insert('a');
    lst.insert('b');
    lst.insert('c');
    lst.insert('d');

    CHECK_THROWS_AS(lst.removeAt(4), std::range_error);
    CHECK_THROWS_AS(lst.removeAt(5), std::range_error);
    CHECK_THROWS_AS(lst[4], std::range_error);
    CHECK_THROWS_AS(lst[5], std::range_error);

    CHECK_THROWS_AS(lst.removeAt(-1), std::range_error);
    CHECK_THROWS_AS(lst[-1], std::range_error);
}


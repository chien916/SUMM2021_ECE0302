#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "deque.hpp"

// TODO


TEST_CASE("Tests", "[deque]") {
    SECTION("test constructor") {
        Deque<int> test;
        REQUIRE(test.isEmpty());
    }
    SECTION("test destructor") {
        /* destructor cannot be directly tested
         * however if this test file compiles
         * it means the destructor works
         */
    }
    SECTION("test isEmpty()") {
        Deque<long int> test;
        REQUIRE(test.isEmpty());
        test.pushBack(1);
        REQUIRE(!test.isEmpty());
        test.popBack();
        REQUIRE(test.isEmpty());
    }
    SECTION("test pushBack()") {
        char arr[6] = {'a', 'b', 'c', 'd', 'e', 'f'};
        Deque<char> test;
        for (char i : arr) {
            test.pushBack(i);
        }
        for (int i = 0; i < 6; i++) {
            REQUIRE(test.back() == (arr[5 - i]));
            test.popBack();
        }
    }
    SECTION("test pushFront()") {
        char arr[6] = {'a', 'b', 'c', 'd', 'e', 'f'};
        Deque<char> test;
        for (char i : arr) {
            test.pushFront(i);
        }
        for (char &i : arr) {
            REQUIRE(test.back() == i);
            test.popBack();
        }
    }
    SECTION("test popFront()") {
        char arr[6] = {'a', 'b', 'c', 'd', 'e', 'f'};
        Deque<char> test;
        for (char i : arr) {
            test.pushBack(i);
        }
        for (char &i : arr) {
            REQUIRE(test.front() == i);
            test.popFront();
        }
    }
    SECTION("test popBack()") {
        char arr[6] = {'a', 'b', 'c', 'd', 'e', 'f'};
        Deque<char> test;
        for (char i : arr) {
            test.pushBack(i);
        }
        for (int i = 0; i < 6; i++) {

            REQUIRE(test.back() == (arr[5 - i]));
            test.popBack();
        }
    }
    SECTION("test front()") {
        char arr[6] = {'a', 'b', 'c', 'd', 'e', 'f'};
        Deque<char> test;
        for (char i : arr) {
            test.pushBack(i);
        }
        for (char &i : arr) {

            REQUIRE(test.front() == i);
            test.popFront();
        }
    }
    SECTION("test back()") {
        char arr[6] = {'a', 'b', 'c', 'd', 'e', 'f'};
        Deque<char> test;
        for (char i : arr) {
            test.pushBack(i);
        }
        for (int i = 0; i < 6; i++) {
            REQUIRE(test.back() == (arr[5 - i]));
            test.popBack();
        }
    }

    SECTION("ifContains()") {
        char arr[6] = {'a', 'b', 'c', 'd', 'e', 'f'};
        Deque<char> test;
        for (char i : arr) {
            test.pushBack(i);
        }
        REQUIRE(test.ifContains('a'));
        REQUIRE(test.ifContains('b'));
        REQUIRE(test.ifContains('c'));
        REQUIRE(test.ifContains('e'));
        REQUIRE(test.ifContains('d'));
        REQUIRE(test.ifContains('f'));
        REQUIRE(!test.ifContains('g'));
    }
    SECTION("test size limit and boundaries") {
        Deque<int> test;
        for (int i = 0; i < 8888; i++) {
            test.pushBack(i);
        }
        for (int i = 0; i < 8888; i++) {
            REQUIRE(test.ifContains(i));
        }
        for (int i = 0; i < 8888; i++) {
            REQUIRE(test.front() == (i));
            test.popFront();
        }
    }


}

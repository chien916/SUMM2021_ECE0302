#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE

#include <iostream>
#include "catch.hpp"
#include "XMLParser.cpp"

using namespace std;

// TODO Implement tests of your Stack class and XMLParser class here

//I did not include any tests on "Bag" and "Node" class because I did not make any changes to them

//THIS IS IMPORTANT, AND PLEASE READ THIS:
//I did not understand how searching frequency of elements mean (I'm not sure if empty tag counted as an element)
//For that reason, in XMLParser.hpp, I included a global bool "MASTER_SWITCH".
//When MASTER_SWITCH is set to TRUE, then Empty Tag WILL counts as element.
//When MASTER_SWITCH is set to FALSE, then Empty Tag WILL NOT counts as element.

//====================================TEST CASES FOR STACK ADT========================================
TEST_CASE("STACK ADT TEST BENCHES COMPILATIONS") {
    Stack<unsigned int> *testPtr;
    SECTION("FUNCTION BEING TESTED: Stack()") {
        testPtr = new Stack<unsigned int>();
        REQUIRE(testPtr->isEmpty());
        REQUIRE(testPtr->size() == 0);
    }
    SECTION("FUNCTION BEING TESTED: ~Stack()") {
        testPtr = new Stack<unsigned int>();
        delete testPtr;
        //Not possible to see if a pointer is pointing to something or not
    }
    SECTION("FUNCTION BEING TESTED: size()") {
        testPtr = new Stack<unsigned int>();
        testPtr->push(1);
        REQUIRE(testPtr->size() == 1);
        testPtr->push(1);
        REQUIRE(testPtr->size() == 2);
        testPtr->pop();
        REQUIRE(testPtr->size() == 1);
        testPtr->pop();
        REQUIRE(testPtr->size() == 0);
        delete testPtr;
    }
    SECTION("FUNCTION BEING TESTED: isEmpty()") {
        testPtr = new Stack<unsigned int>();
        REQUIRE(testPtr->isEmpty() == true);
        testPtr->push(1);
        REQUIRE(testPtr->isEmpty() == false);
        delete testPtr;
    }
    SECTION("FUNCTION BEING TESTED: push()") {
        testPtr = new Stack<unsigned int>();
        testPtr->push(1);
        REQUIRE(testPtr->peek() == 1);
        testPtr->push(2);
        REQUIRE(testPtr->peek() == 2);
        testPtr->push(3);
        REQUIRE(testPtr->peek() == 3);
        testPtr->push(4);
        REQUIRE(testPtr->peek() == 4);
        testPtr->push(5);
        REQUIRE(testPtr->peek() == 5);
        delete testPtr;
    }
    SECTION("FUNCTION BEING TESTED: peek()") {
        testPtr = new Stack<unsigned int>();
        testPtr->push(1);
        REQUIRE(testPtr->peek() == 1);
        testPtr->push(2);
        REQUIRE(testPtr->peek() == 2);
        testPtr->push(3);
        REQUIRE(testPtr->peek() == 3);
        testPtr->push(4);
        REQUIRE(testPtr->peek() == 4);
        testPtr->push(5);
        REQUIRE(testPtr->peek() == 5);
        delete testPtr;
    }
    SECTION("FUNCTION BEING TESTED: pop()") {
        testPtr = new Stack<unsigned int>();
        testPtr->push(1);
        testPtr->push(2);
        testPtr->push(3);
        testPtr->push(4);
        testPtr->push(5);
        testPtr->pop();
        REQUIRE(testPtr->peek() == 4);
        REQUIRE(testPtr->pop() == 4);
        REQUIRE(testPtr->pop() == 3);
        REQUIRE(testPtr->pop() == 2);
        REQUIRE(testPtr->pop() == 1);
        delete testPtr;
    }
    SECTION("FUNCTION BEING TESTED: clear()") {
        testPtr = new Stack<unsigned int>();
        testPtr->push(1);
        testPtr->push(2);
        testPtr->push(3);
        testPtr->push(4);
        testPtr->push(5);
        testPtr->clear();
        REQUIRE(testPtr->isEmpty());
        REQUIRE(testPtr->size() == 0);
        delete testPtr;
    }
}
//====================================TEST CASES FOR XML PARSER========================================
TEST_CASE("XML PARSER TEST BENCHES COMPILATIONS") {
    XMLParser *testPtr;
    string txtFile = "E:/SM2021/ece0302/Projects/pj3/pj3/xmlFile.txt";
    SECTION("FUNCTION BEING TESTED: XMLParser()") {
        testPtr = new XMLParser();
        Bag<std::string> *bagPtr;
        Stack<std::string> *stackPtr;
        std::vector<TokenStruct> tokenVec;
        testPtr->getPtr(bagPtr, stackPtr, tokenVec);
        REQUIRE(bagPtr->isEmpty());
        REQUIRE(stackPtr->isEmpty());
        delete testPtr;
    }
    SECTION("FUNCTION BEING TESTED: tokenizeInputString()") {
        testPtr = new XMLParser();
        Bag<std::string> *bagPtr;
        Stack<std::string> *stackPtr;
        std::vector<TokenStruct> tokenVec;
        testPtr->getPtr(bagPtr, stackPtr, tokenVec);
        REQUIRE(testPtr->tokenizeInputString("<><><>") == true);
        REQUIRE(testPtr->tokenizeInputString("<><<<>") == false);
        REQUIRE(testPtr->tokenizeInputString("<a><b><c>") == true);
        REQUIRE(testPtr->tokenizeInputString("<?a?><b><c>") == true);
        REQUIRE(testPtr->tokenizeInputString(">>>>>") == false);
        delete testPtr;
    }
    SECTION("FUNCTION BEING TESTED: parseTokenizedInput()") {
        bool success;
        string inputString;
        ifstream myfile;
        myfile.open("E:/SM2021/ece0302/Projects/pj3/pj3/xmlFile.txt");
        XMLParser myParser;
        string lineReceived;
        bool finishExtracting = false;
        if (myfile.is_open()) {
            while (!finishExtracting) {
                getline(myfile, lineReceived);
                inputString += lineReceived;
                if (lineReceived == "")
                    finishExtracting = true;
            }
            myfile.close();
        }
        myParser.tokenizeInputString(inputString);
        myParser.initializeTokenizedInputVector();
        vector<TokenStruct> tokenizedInput = myParser.returnTokenizedInput();
        REQUIRE(myParser.parseTokenizedInput() == 1);
    }
    SECTION("FUNCTION BEING TESTED: containsElementName()") {
        bool success;
        string inputString;
        ifstream myfile;
        myfile.open("E:/SM2021/ece0302/Projects/pj3/pj3/xmlFile.txt");
        XMLParser myParser;
        string lineReceived;
        bool finishExtracting = false;
        if (myfile.is_open()) {
            while (!finishExtracting) {
                getline(myfile, lineReceived);
                inputString += lineReceived;
                if (lineReceived == "")
                    finishExtracting = true;
            }
            myfile.close();
        }
        myParser.tokenizeInputString(inputString);
        myParser.initializeTokenizedInputVector();
        vector<TokenStruct> tokenizedInput = myParser.returnTokenizedInput();
        myParser.parseTokenizedInput();
        REQUIRE(myParser.containsElementName("heading") == 1);
        REQUIRE(myParser.containsElementName("note") == 1);
        REQUIRE(myParser.containsElementName("WEIRDNAME") == 0);
        REQUIRE(myParser.containsElementName("body") == 1);
    }
    SECTION("FUNCTION BEING TESTED: frequencyElementName()") {
        bool success;
        string inputString;
        ifstream myfile;
        myfile.open("E:/SM2021/ece0302/Projects/pj3/pj3/xmlFile.txt");
        XMLParser myParser;
        string lineReceived;
        bool finishExtracting = false;
        if (myfile.is_open()) {
            while (!finishExtracting) {
                getline(myfile, lineReceived);
                inputString += lineReceived;
                if (lineReceived == "")
                    finishExtracting = true;
            }
            myfile.close();
        }
        myParser.tokenizeInputString(inputString);
        myParser.initializeTokenizedInputVector();
        vector<TokenStruct> tokenizedInput = myParser.returnTokenizedInput();
        myParser.parseTokenizedInput();
        REQUIRE(myParser.frequencyElementName("heading") == 1);
        REQUIRE(myParser.frequencyElementName("note") == 2);
        REQUIRE(myParser.frequencyElementName("WEIRDNAME") == 0);
        REQUIRE(myParser.frequencyElementName("body") == 1);
    }

}


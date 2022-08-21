// Project 3 -- XML Parsing Project

/** XML parsing class implementation.
    @file XMLParser.cpp */

#include <string>
#include <assert.h>
#include "XMLParser.hpp"

// TODO: Implement the constructor here
XMLParser::XMLParser() {
    elementNameBag = new Bag<std::string>;
    parseStack = new Stack<std::string>;
}  // end default constructor

// TODO: Implement the destructor here
XMLParser::~XMLParser() {
    elementNameBag->clear();
    parseStack->clear();
    delete elementNameBag;
    delete parseStack;
}  // end destructor

// TODO: Implement the tokenizeInputString method
bool XMLParser::tokenizeInputString(const std::string &inputString) {//done and checked
    int indexCursor = 0;//cursor is initially set to 0
    std::string tempString;
    //-1 - writing content outside of brackets
    //0 - undetermined
    //1 - writing content inside of brackets
    int flag = 0;
    while (indexCursor < inputString.size()) {
        char tempChar = inputString.at(indexCursor);//extract char with the given index from string
        switch (tempChar) {
            case '<':
                if (flag == 1) {//                      <---    <
                    return false;
                } else if (flag == -1) {//              ---     <
                    flag = 1;
                    unclassifiedTokenizedInputVector.push_back(tempString);
                    tempString.clear();
                    tempString.push_back(tempChar);
                } else if (flag == 0) {//               >       <
                    flag = 1;
                    tempString.push_back(tempChar);
                }
                break;
            case '>':
                if (flag == 1) {//                      <---    >
                    flag = 0;
                    tempString.push_back(tempChar);
                    unclassifiedTokenizedInputVector.push_back(tempString);
                    tempString.clear();
                } else if (flag == -1) {//              ---     >
                    return false;

                } else if (flag == 0) {//               >       >
                    return false;
                }
                break;
            default: // case others (content/name/attributes)
                if (flag == 1) {//                      <       ---
                    tempString.push_back(tempChar);
                } else if (flag == -1) {//              ---     ---
                    tempString.push_back(tempChar);
                } else if (flag == 0) {//               >       ---
                    flag = -1;
                    tempString.push_back(tempChar);
                }
                break;
        }
        indexCursor++;
    }
    return true;


}  // end

// TODO: Implement a helper function to delete attributes from a START_TAG
// or EMPTY_TAG string (you can change this...)
static std::string deleteAttributes(std::string input) {
    StringTokenType tempType;
    XMLParser test;
    test.checkClassValidity(input, tempType);
    input = test.deattributize(input, tempType);
    return input;
}

// TODO: Implement the parseTokenizedInput method here
bool XMLParser::parseTokenizedInput() {
    for (const auto &tempStr : unclassifiedTokenizedInputVector) {
        StringTokenType dummyArgument;
        bool ifValid = checkClassValidity(tempStr, dummyArgument);
        if (!ifValid) {
            return false;
        }
    }
    return checkStructure();
}


// TODO: Implement the clear method here
void XMLParser::clear() {
    elementNameBag->clear();
    parseStack->clear();
    delete elementNameBag;
    delete parseStack;
}

vector<TokenStruct> XMLParser::returnTokenizedInput() const {
    vector<TokenStruct> toReturn;
    toReturn.clear();
    for (auto tempStr : unclassifiedTokenizedInputVector) {
        auto *tokenTypeDetectedAdr = new StringTokenType;
        checkClassValidity(tempStr, *tokenTypeDetectedAdr);
        tempStr = debracketize(tempStr);
        TokenStruct structToStore;
        structToStore.tokenString = tempStr;
        structToStore.tokenType = *tokenTypeDetectedAdr;
        toReturn.push_back(structToStore);
        delete tokenTypeDetectedAdr;
    }

    return toReturn;
}

// TODO: Implement the containsElementName method
bool XMLParser::containsElementName(const std::string &inputString) const {
    return (frequencyElementName(inputString) > 0);
}

// TODO: Implement the frequencyElementName method
int XMLParser::frequencyElementName(const std::string &inputString) const {
    int frequency = 0;
    for (const auto &i : tokenizedInputVector) {
        StringTokenType tempType = i.tokenType;
        std::string tempString = i.tokenString;
        if (tempType == START_TAG && tempString == inputString)
            frequency++;
        else if (tempType == EMPTY_TAG && tempString == (inputString + "/") && MASTER_SWITCH)
            frequency++;
    }
    return frequency;
}

bool XMLParser::checkClassValidity(std::string tokenStr, StringTokenType &returnType) const {//done and checked
    if (!(tokenStr[0] == '<' && tokenStr[tokenStr.size() - 1] == '>')) {
        returnType = CONTENT;
        return true;
    }
    tokenStr = debracketize(tokenStr);
    if (tokenStr[0] == '?' && tokenStr[tokenStr.size() - 1] == '?') {
        returnType = DECLARATION;
        return true;
    }
    std::vector<size_t> slashesTestVector = searchForSlashes(tokenStr);
    std::vector<size_t> spacesTestVector = searchForSpaces(tokenStr);
    int numberOfSlashes = slashesTestVector.size();
    int numberOfSpaces = spacesTestVector.size();
    if (numberOfSlashes == 0) {
        if (numberOfSpaces > 0) {
            tokenStr.erase(tokenStr.begin() + spacesTestVector[0], tokenStr.end());
        }
        if (searchForIllegalCharInName(tokenStr)) {
            returnType = START_TAG;
            return true;
        } else {
            return false;
        }
    } else if (numberOfSlashes == 1 && numberOfSpaces == 0) {
        if (slashesTestVector[0] == 0) {
            if (searchForIllegalCharInName(tokenStr)) {
                returnType = END_TAG;
                return true;
            } else {
                return false;
            }
        } else if (slashesTestVector[0] == (tokenStr.size() - 1)) {
            if (numberOfSpaces > 0) {
                tokenStr.erase(tokenStr.begin() + spacesTestVector[0], tokenStr.end() - 1);
            }
            if (searchForIllegalCharInName(tokenStr)) {
                returnType = EMPTY_TAG;
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    } else {
        return false;
    }

}

bool XMLParser::searchForIllegalCharInName(const std::string &searchStr) const {//done and checked
    for (int i = 0; i < searchStr.size(); i++) {
        char tempChar = searchStr.at(i);
        bool interval1 = (tempChar >= 32 && tempChar <= 46);// / is excluded here
        bool interval2 = (tempChar >= 58 && tempChar <= 64);
        bool interval3 = (tempChar >= 91 && tempChar <= 96);
        bool interval4 = (tempChar >= 123 && tempChar <= 126);
        if (interval1 || interval2 || interval3 || interval4) {
            return false;
        }
    }
    return true;
}

std::vector<size_t> XMLParser::searchForSlashes(const std::string &searchStr) const {//done and checked
    std::vector<size_t> toReturn;
    std::string slash = "/";
    std::size_t lastFoundIndex = -1;
    do {
        lastFoundIndex = searchStr.find(slash, lastFoundIndex + 1);
        if (lastFoundIndex != string::npos) {
            toReturn.push_back(lastFoundIndex);
        }
    } while (lastFoundIndex != string::npos);
    return toReturn;
}

std::vector<size_t> XMLParser::searchForSpaces(const std::string &searchStr) const {//done and checked
    std::vector<size_t> toReturn;
    std::string space = " ";
    std::size_t lastFoundIndex = -1;
    do {
        lastFoundIndex = searchStr.find(space, lastFoundIndex + 1);
        if (lastFoundIndex != string::npos) {
            toReturn.push_back(lastFoundIndex);
        }
    } while (lastFoundIndex != string::npos);
    //auto o=1;
    return toReturn;
}

std::string XMLParser::debracketize(std::string &inputStr) const {
    std::string tokenStr = inputStr;
    if (inputStr[0] == '<' && inputStr[inputStr.size() - 1] == '>') {
        tokenStr.erase(tokenStr.begin());//delete <
        tokenStr.erase(tokenStr.end() - 1);//delete >
    }
    return tokenStr;
}

std::string XMLParser::struct2String(const TokenStruct &inp) const {
    string typeDisplay;
    StringTokenType typeTemp = inp.tokenType;
    if (typeTemp == START_TAG)
        typeDisplay = "START_TAG";
    else if (typeTemp == END_TAG)
        typeDisplay = "END_TAG";
    else if (typeTemp == EMPTY_TAG)
        typeDisplay = "EMPTY_TAG";
    else if (typeTemp == CONTENT)
        typeDisplay = "CONTENT";
    else if (typeTemp == DECLARATION)
        typeDisplay = "DECLARATION";
    else {
        throw std::logic_error("struct string convert error");
    }
    return typeDisplay;
}

bool XMLParser::checkStructure() const {
    if (tokenizedInputVector.empty()) {
        throw logic_error("check structure fail: tokenized vector is empty");
    } else {
        parseStack->clear();
        if (tokenizedInputVector.at(0).tokenType != DECLARATION)
            return false;
        for (int i = 1; i < tokenizedInputVector.size(); i++) {
            TokenStruct tempStruct = tokenizedInputVector.at(i);
            std::string tempString = tempStruct.tokenString;
            StringTokenType tempType = tempStruct.tokenType;
            if (tempType == CONTENT) {
                if (parseStack->isEmpty())
                    return false;
            } else if (tempType == END_TAG) {
                if (parseStack->isEmpty())
                    return false;
                else if ("/" + parseStack->peek() != tempString)
                    return false;
                else if ("/" + parseStack->peek() == tempString) {
                    parseStack->pop();
                }
            } else if (tempType == START_TAG) {
                tempString = deattributize(tempString, tempType);
                parseStack->push(tempString);
            } else if (tempType == EMPTY_TAG) {
                parseStack->push(tempString);
                parseStack->pop();
            } else if (tempType == DECLARATION)
                return false;
        }
        return true;
    }
}

void XMLParser::initializeTokenizedInputVector() {
    tokenizedInputVector = returnTokenizedInput();
}

std::string XMLParser::deattributize(std::string &inputStr, StringTokenType inputType) const {
    string tokenStr = inputStr;
    std::vector<size_t> spacesTestVector = searchForSpaces(tokenStr);
    int numberOfSpaces = spacesTestVector.size();
    if (numberOfSpaces > 0) {
        if (inputType == START_TAG)
            tokenStr.erase(tokenStr.begin() + spacesTestVector[0], tokenStr.end());
        else if (inputType == EMPTY_TAG)
            tokenStr.erase(tokenStr.begin() + spacesTestVector[0], tokenStr.end() - 1);
        else
            throw (std::logic_error("de attributize error : wrong type"));
    }
    return tokenStr;
}

void XMLParser::getPtr(Bag<std::string>* &bagPtr,Stack<std::string>*& stackPtr,std::vector<TokenStruct> &tokenVec) const{
    bagPtr=elementNameBag;
    stackPtr=parseStack;
    tokenVec=tokenizedInputVector;
}
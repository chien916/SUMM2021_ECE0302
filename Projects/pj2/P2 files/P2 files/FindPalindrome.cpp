#include <string>
#include <vector>
#include <iostream>
#include <locale>
#include "FindPalindrome.hpp"

using namespace std;

//------------------- HELPER FUNCTIONS -----------------------------------------

// non-class helper functions go here, should be declared as "static" so that
// their scope is limited

// helper function to convert string to lower case
static void convertToLowerCase(string &value) {
    locale loc;
    for (int i = 0; i < value.size(); i++) {
        value[i] = tolower(value[i], loc);
    }
}

//------------------- PRIVATE CLASS METHODS ------------------------------------

// private recursive function. Must use this signature!
void FindPalindrome::recursiveFindPalindromes(vector<string>
                                              candidateStringVector, vector<string> currentStringVector) {
    if (currentStringVector.size() == 0) {
        if (objVectorString.size() == 0) {
            return;
        } else {
            currentStringVector = objVectorString;
        }
    }
    int leftVectorSize = candidateStringVector.size();
    int rightVectorSize = currentStringVector.size();
    if (rightVectorSize == 1) {//boundary condition: when current string vector becomes empty
        candidateStringVector.push_back(currentStringVector.at(0));
        string stringToCheckPalindromes = stringVectorToString(candidateStringVector, 1);
        bool ifPalindromes = isPalindrome(stringToCheckPalindromes);//check if given string is palindrome
        if (ifPalindromes) {
            cout << "--PALINDROMES DETECTED! STR:" << stringToCheckPalindromes << "\n";
            Palindromes.push_back(candidateStringVector);
        }
    } else {//other conditions: more recursive calls are needed
        for (int i = 0; i < rightVectorSize; i++) {//for each obj in currentStringVector
            string stringToTransfer = currentStringVector.at(i);//extract target string
            currentStringVector.erase(currentStringVector.begin() + i);//remove extracted string
            candidateStringVector.push_back(stringToTransfer);//push back extracted string
            recursiveFindPalindromes(candidateStringVector, currentStringVector);//recursively call
            candidateStringVector.pop_back();//delete added string
            currentStringVector.insert(currentStringVector.begin() + i, stringToTransfer);

        }
    }

}

// private function to determine if a string is a palindrome (given, you
// may change this if you want)
bool FindPalindrome::isPalindrome(string currentString) const {
    locale loc;
    // make sure that the string is lower case...
    convertToLowerCase(currentString);
    // see if the characters are symmetric...
    int stringLength = currentString.size();
    for (int i = 0; i < stringLength / 2; i++) {
        if (currentString[i] != currentString[stringLength - i - 1]) {
            return false;
        }
    }
    return true;
}

bool FindPalindrome::scanString(const std::string &stringToScan) {
    int stringSize = stringToScan.size();
    bool ifValid = true;
    for (int i = 0; i < stringSize; i++) {
        char charToCheck = stringToScan[i];
        bool ifLowerLetter = charToCheck <= 'z' && charToCheck >= 'a';
        bool ifUpperLetter = charToCheck <= 'Z' && charToCheck >= 'A';
        if ((!ifLowerLetter) && (!ifUpperLetter)) {
            ifValid = false;
            break;
        }
    }
    return ifValid;
}

string FindPalindrome::stringVectorToString(const vector<string> &stringVector, const int control) {
    string sumString = "";
    for (int i = 0; i < stringVector.size(); i++) {
        sumString += stringVector.at(i);
    }
    if (control == 1) {
        convertToLowerCase(sumString);
    }
    return sumString;
}

void FindPalindrome::recomputePalindrome() {
    bool test1 = cutTest1(objVectorString);
    if (test1) {
        vector<string> empty;
        recursiveFindPalindromes(empty, empty);
    }
};
//------------------- PUBLIC CLASS METHODS -------------------------------------

FindPalindrome::FindPalindrome() {
    clear();
}

FindPalindrome::~FindPalindrome() {
    clear();
}

int FindPalindrome::number() const {
    return Palindromes.size();
}

void FindPalindrome::clear() {
    objVectorString.clear();
    Palindromes.clear();
}

bool FindPalindrome::cutTest1(const vector<string> &stringVector) {
    string sumString = stringVectorToString(stringVector, 1);
    //cout << "\n****** CUTTEST1TEST RECEIVED STRING:" << sumString << endl;
    int letterCount[26] = {0};
    for (int i = 0; i < sumString.size(); i++) {
        letterCount[sumString[i] - 'a']++;
    }
    int timesOfSingleLetterAppearance = 0;
    for (int i = 0; i < 26; i++) {
        if (letterCount[i] % 2 != 0) {
            timesOfSingleLetterAppearance++;
        }
    }
    bool ifTestIsPassed = (timesOfSingleLetterAppearance <= 1);
    return ifTestIsPassed;
}

bool FindPalindrome::cutTest2(const vector<string> &stringVector1,
                              const vector<string> &stringVector2) {
    string sumString1 = stringVectorToString(stringVector1, 1);
    string sumString2 = stringVectorToString(stringVector2, 1);
    //cout<<"\n****** CUTTEST2TEST RECEIVED STRING1:"<<sumString1<<endl;
    //cout<<"\n****** CUTTEST2TEST RECEIVED STRING2:"<<sumString2<<endl;
    for (int i = 0; i < sumString1.size(); i++) {
        //cout<<"\nFINDING "<<sumString1[i]<<" FROM "<<sumString2<<endl;
        string::size_type positionFound = sumString2.find(sumString1[i]);
        if (positionFound != sumString2.npos) {
            sumString2.erase(positionFound, 1);
        } else {
            //cout << "\n****** TEST2 DID NOT pASS:" << endl;
            //cout << "\n****** CUTTEST2TEST RECEIVED STRING1:" << sumString1 << endl;
            //cout << "\n****** CUTTEST2TEST RECEIVED STRING2:" << sumString2 << endl;
            return false;
        }
    }
    return true;
}

bool FindPalindrome::add(const string &value) {
    bool ifValid = scanString(value);
    if (ifValid) {
        objVectorString.push_back(value);
        recomputePalindrome();
        return true;
    } else {
        return false;
    }

}

bool FindPalindrome::add(const vector<string> &stringVector) {
    int sizeOfStringVector = stringVector.size();
    for (int i = 0; i < sizeOfStringVector; i++) {
        bool ifAdded = add(stringVector[i]);
        if (!ifAdded) {
            return false;
        }
    }
    recomputePalindrome();
    return true;
}

vector<vector<string> > FindPalindrome::toVector() const {
    return Palindromes;
}


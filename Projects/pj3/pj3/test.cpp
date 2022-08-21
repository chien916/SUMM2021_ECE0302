#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
typedef enum {START_TAG = 1, END_TAG, EMPTY_TAG, CONTENT, DECLARATION} StringTokenType;
std::vector<size_t>  searchForSlashes(std::string searchStr) {
    std::vector<size_t> toReturn;
    std::string slash = "/";
    std::size_t lastFoundIndex = 0;
    do {
        lastFoundIndex = searchStr.find(slash, lastFoundIndex);
        if (lastFoundIndex != string::npos) {
            toReturn.push_back(lastFoundIndex);
        }
    } while (lastFoundIndex != string::npos);
    return toReturn;
}
std::vector<size_t> searchForSpaces(const std::string &searchStr) {//done and checked
    std::vector<size_t> toReturn;
    std::string space = " ";
    std::size_t lastFoundIndex = -1;
    do {
        lastFoundIndex = searchStr.find(space, lastFoundIndex + 1);
        if (lastFoundIndex != string::npos) {
            toReturn.push_back(lastFoundIndex);
        }
    } while (lastFoundIndex != string::npos);
    return toReturn;
}

bool searchForIllegalCharInName(const std::string &searchStr) {//done and checked
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
bool checkClassValidity(std::string tokenStr, StringTokenType &returnType) {
    tokenStr.erase(tokenStr.begin());//delete <
    tokenStr.erase(tokenStr.end() - 1);//delete >
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
            tokenStr.erase(tokenStr.begin() + spacesTestVector[0]);
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
        } else if ((slashesTestVector[0] == (tokenStr.size() - 1)) && numberOfSpaces == 0) {
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
int main() {
    vector<size_t> res = searchForSlashes("fwgverb/ergergvreg/regerg/erg");
    if (res.empty() == 0) {
        for (int i = 0; i < res.size(); i++) {
            cout << "\n " << res[i];
        }
    }
}
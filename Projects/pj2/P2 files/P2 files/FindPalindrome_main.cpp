#include <iostream>
#include "FindPalindrome.hpp"

using namespace std;

int main() {
    FindPalindrome f;
    string newString("1");
    cout << "\n******* Project 1 Main *********\n\n";

/*
    bool inputMode2 = 1;
    while (inputMode2) {
        cout << "\n TEST TESTS STR1:";
        string inputString1;
        cin >> inputString1;
        if (inputString1 == "0") {
            inputMode2 = 0;
        }
        cout << "\n TEST TESTS STR2:";
        string inputString2;
        cin >> inputString2;
        vector<string> vec1;
        vector<string> vec2;
        vec1.push_back(inputString1);
        vec2.push_back(inputString2);
        bool status1 = f.cutTest1(vec1);
        bool status2 = f.cutTest1(vec2);
        bool status3 = f.cutTest2(vec1, vec2);
        cout << "TEST RESULT: " << status1 << status2 << status3 << endl;
    }
*/

    bool inputMode = 1;
    while (inputMode) {
        cout << "\n INPUT:";
        string inputString;
        cin >> inputString;
        if (inputString == "0") {
            inputMode = 0;
            break;
        } else {
            bool ifInputted = f.add(inputString);
            if (ifInputted) {
                cout << " %%INPUT SUCESSFUL :[" << inputString << "]\n";
            } else {
                cout << " %%INPUT FAILED :[" << inputString << "]\n";
            }
        }
    }

    f.add("no");
    cout << "\nNumber of sentence palindromes are:  " << f.number() << endl;
    cout << "\nThe sentence palindromes are:" << endl;
    vector<vector<string>> vectorList = f.toVector();
    for (int i = 0; i < vectorList.size(); i++) {
        for (int j = 0; j < vectorList[i].size(); j++) {
            cout << vectorList[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << "\n******* Project 1 Main *********\n\n";
    return 0;
}


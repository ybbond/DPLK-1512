#include <algorithm>
#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

bool isPalindrome(string input);
string removeNonAlpha(string input);
string stringToLowerCase(string input);

// // string daftarKata[4] = { "Kodok", "koDOk", "KOdok", "koDOK", "Kodok" };
//
// // { "Kodok", "kuntul" };
// vector<string> test;
// test.push_back("Kodok");
// test.push_back("kuntul");

int main() {
    string testString;
    getline(cin, testString);

    istringstream iss(testString);
    string currentWord;
    vector<string> testWordList, palindromeWordList;

    while (iss >> currentWord) {
        // "HAHOHE!!HAHA" → removeNonAlpha → "HAHOHEHAHA"
        string parsed = removeNonAlpha(currentWord);
        // "HAHOHEHAHA" → stringToLowerCase → "hahohehaha"
        string lower = stringToLowerCase(parsed);
        testWordList.push_back(stringToLowerCase(lower));
    }

    // sama aja kaya
    // for (int i = 0; i < testWordList.size(); i++) {
    //     string testWord = testWordList[i];
    for (string testWord : testWordList) {
        if (isPalindrome(testWord)) {
            palindromeWordList.push_back(testWord);
        }
    }

    cout << palindromeWordList.size() << endl;

    // sama aja kaya
    // for (int i = 0; i < palindromeWordList.size(); i++) {
    //     string curr = palindromeWordList[i];
    for (string curr : palindromeWordList) {
        cout << curr << endl;
    }

    return 0;
}

// KODOK
// KATAK
// NABABAN
// KASUR INI RUSAK
// PALINDROME = kalau karakter di index 0, sama dengan index terakhir

bool isPalindrome(string input) {
    int testStringLength = input.length(); // ← 6

    // 6.0 / 2 = 3.0 → float / double
    // 6   / 2 = 3   → int
    // i sedang 0
    for (int i = 0; i < (testStringLength / 2); i++) {
        char currentChar = input[i];                         // H
        //                          6            - 1 - 0     // 5
        char mirrorChar = input[testStringLength - 1 - i];   // H

        if (currentChar != mirrorChar) {
            return false;
        }
    }

    return true;
}

string removeNonAlpha(string input) {
    string result;
    for (char c : input) {
        if (isalpha(c)) {
            result += c;
        }
    }
    return result;
}

string stringToLowerCase(string input) {
    transform(
        input.begin(),
        input.end(),
        input.begin(),
        [](unsigned char c){ return tolower(c); }
    );

    return input;
}

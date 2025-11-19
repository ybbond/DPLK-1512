#include <fstream>
#include <iostream>

using namespace std;

int main() {
    string fileName = "text.txt";
    ifstream textFile(fileName);

    if (!textFile) {
        cout << "Error Code 400: file cannot be opened" << endl;
        return 400;
    }

    int charCount = 0;
    int wordCount = 0;
    int lineCount = 0;
    string currentLine;

    while (getline(textFile, currentLine)) {
        lineCount++;
        charCount += currentLine.length();

        bool isInWord = false;
        for (char c : currentLine) {
            if (c == ' ' || c == '\t') {
                isInWord = false;
            } else {
                if (!isInWord) {
                    wordCount++;
                    isInWord = true;
                }
            }
        }
    }

    textFile.close();

    cout << "Characters: " << charCount << endl;
    cout << "Words     : " << wordCount << endl;
    cout << "Lines     : " << lineCount << endl;

    cout << endl << "Notes: character count excluding newlines." << endl;

    return 0;
}

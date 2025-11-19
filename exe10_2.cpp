#include <fstream>
#include <iostream>

using namespace std;

int main() {
    string fileName = "scores.txt";
    ifstream scoreFile(fileName);

    if (!scoreFile) {
        cout << "Error Code 400: file cannot be opened" << endl;
        return 400;
    }

    string currentName;
    int currentScore;
    double sumScore = 0;
    int countScore = 0;

    cout << "Student and scores list:" << endl;
    while (scoreFile >> currentName >> currentScore) {
        sumScore += currentScore;
        countScore++;
        cout << currentName << " " << currentScore << endl;
    }

    scoreFile.close();

    cout << endl;
    cout << "Average of scores: " << sumScore / countScore << endl;

    return 0;
}

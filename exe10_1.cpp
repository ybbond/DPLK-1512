#include <fstream>
#include <iostream>

using namespace std;

string padLeft(string, int, char);

int main() {
    string fileName = "students.txt";
    ofstream outFile(fileName);
    int studentCount;
    cout << "How many students do you want to input? ";
    cin >> studentCount;

    cout << endl;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int count = 0; count < studentCount; count++) {
        cout << "Student #" << padLeft(to_string(count + 1), 3, '0') << ": ";
        string currentStudent;
        getline(cin, currentStudent);
        outFile << currentStudent <<endl;
    }

    outFile.close();
    cout << endl
         << "Successfully written "
         << studentCount
         << " students to "
         << fileName
         << endl;

    return 0;
}

string padLeft(string s, int totalWidth, char paddingChar) {
    if (s.length() < totalWidth) {
        s.insert(0, totalWidth - s.length(), paddingChar);
    }
    return s;
}

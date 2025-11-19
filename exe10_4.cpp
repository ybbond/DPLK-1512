#include <fstream>
#include <iostream>

using namespace std;

int main() {
    string fileName = "log.txt";
    fstream logFile(fileName, ios::in | ios::out | ios::app);

    if (!logFile) {
        cout << "Error Code 400: file cannot be opened" << endl;
        return 400;
    }

    string logMessage;
    cout << "Enter log message: ";
    getline(cin, logMessage);

    logFile << "LOG: " << logMessage << endl; 

    logFile.close();

    return 0;
}

#include <iostream>
#include <string>

using namespace std;

int getIntValidate(string coutPrompt);

int main() {
    string fullName;
    int task1, task2, midExam, finExam, absence;

    cout << "Name: ";
    getline(cin, fullName);
    task1 = getIntValidate("KAT 1 (0-100): ");
    task2 = getIntValidate("KAT 2 (0-100): ");
    midExam = getIntValidate("Mid Exam (0-100): ");
    finExam = getIntValidate("Final Exam (0-100): ");
    absence = getIntValidate("Attendance (x times): ");

    double score = (task1 * 0.1) + (task2 * 0.3) + (midExam * 0.25) + (finExam * 0.35);

    char grade;
    string status;

    if      (89 < score)                grade = 'A';
    else if (80 < score && score <= 89) grade = 'B';
    else if (70 < score && score <= 80) grade = 'C';
    else if (60 < score && score <= 70) grade = 'D';
    else                                grade = 'E';

    if (absence > 2)                    grade = 'E';

    switch (grade) {
        case 'E':
            status = "Fail";
            break;
        default:
            status = "Pass";
            break;
    }

    cout << endl << endl
         << "=== Result ===" << endl
         << "Name: " << fullName << endl
         << "Final Score: " << score << endl
         << "Grade: " << grade << endl
         << "Status: " << status << endl;

    return 0;
}

int getIntValidate(string coutPrompt) {
    int value;
    cout << coutPrompt;
    cin >> value;
    while (cin.fail()) {
        cout << "Invalid integer, please input valid number!" << endl << endl;
        cout << coutPrompt;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> value;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return value;
}

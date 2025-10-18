#include <iostream>
#include <string>

using namespace std;

int main() {
	string fullName, studentId, hobby;

	cout << "Hello newcomer! This is program to gather new student's data." << endl << endl;
	cout << "First, please input your full name: ";
	getline(cin, fullName);

	cout << endl << "Nice! Hi " << fullName << "!" << endl << endl;
	cout << "Please input your student id (NIM): ";
	getline(cin, studentId);

	cout << endl << "That's great! Now I'm sure that you have a hobby right?" << endl << endl;
	cout << "Please describe your hobby(s) here: ";
	getline(cin, hobby);

	cout << endl << "That's it. Thanks. Please assess whether this following sentence is correct:" << endl << endl;
	cout << "My name is "
		 << fullName
		 << ", my Student ID is "
		 << studentId
		 << ", and my hobby is "
		 << hobby
		 << "." << endl;

    return 0;
}

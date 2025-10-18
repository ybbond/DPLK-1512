#include <iostream>

using namespace std;

void printResult(char choice, double firstNumber, double secondNumber, double result);
char getChoiceValidate();
double getIntValidate(string coutPrompt);

int main() {
	char choice;
	double first, second;
	do {
		cout << "Menu:" << endl
			 << "+ Addition" << endl
			 << "- Subtraction" << endl
			 << "* Multiplication" << endl
			 << "/ Division" << endl
			 << "0 Exit" << endl;

		choice = getChoiceValidate();
		if (choice == '0') {
			cout << "Exiting program..." << endl;
			break;
		}

		first = getIntValidate("Enter first number: ");
		second = getIntValidate("Enter second number: ");

		switch (choice) {
			case '+':
				printResult(choice, first, second, first + second);
				break;
			case '-':
				printResult(choice, first, second, first - second);
				break;
			case '*':
				printResult(choice, first, second, first * second);
				break;
			case '/':
				if (second == 0) {
					cout << "Error: Division by zero is not allowed!";
					break;
				}
				printResult(choice, first, second, first / second);
				break;
		}
	} while (choice != '0');
}

void printResult(char choice, double firstNumber, double secondNumber, double result) {
	cout << "Result of " << firstNumber << " " << choice << " " << secondNumber << " is: " << result << endl << endl;
}

char getChoiceValidate() {
    char value;
    cout << "Enter your choice: ";
    cin >> value;
    while (value != '+' && value != '-' && value != '*' && value != '/' && value != '0') {
        cout << "Invalid choice, please choose based on menu!" << endl << endl;
        cout << "Enter your choice: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> value;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return value;
}

double getIntValidate(string coutPrompt) {
    double value;
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

#include <iostream>
#include <limits>

using namespace std;

int main() {
	int length, width;

	cout << "This is Rectangle Measurement Program" << endl << endl;

	cout << "Enter length of rectangle: ";
	cin >> length;

	while (cin.fail()) {
		cout << "Invalid input. Please enter a valid number for length: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> length;
	}

	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "Enter width of rectangle: ";
	cin >> width;

	while (cin.fail()) {
		cout << "Invalid input. Please enter a valid number for width: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> width;
	}

	cout << endl << "Rectangle's Properties:" << endl
		 << "- length    = " << length << endl
		 << "- width     = " << width << endl
		 << "- area      = " << length * width << endl
		 << "- perimeter = " << 2 * (length + width) << endl;

	cout << endl << "Formula used:" << endl
		 << "- area is calculated by length * width" << endl
		 << "- perimeter is calculated by 2 * (length + width)" << endl;
}

#include <iostream>
#include <string>

using namespace std;

int main() {
	string celsiusString;

	cout << "Enter temperature in Celcius: ";
	cin >> celsiusString;

	bool isContainsComma = celsiusString.find(",");
	replace(celsiusString.begin(), celsiusString.end(), ',', '.');

	double celsiusDouble = stod(celsiusString);
	double fahrenheitDouble = (celsiusDouble * 9 / 5) + 32;
	string fahrenheitString = to_string(fahrenheitDouble);
	if (isContainsComma) {
		replace(fahrenheitString.begin(), fahrenheitString.end(), '.', ',');
		replace(celsiusString.begin(), celsiusString.end(), '.', ',');
	}

	cout << celsiusString
		 << "°C is equal to "
		 << fahrenheitString
		 << "°F"
		 << endl;
}

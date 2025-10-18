#include <iostream>
#include <string>

using namespace std;

int main() {
    string celsiusString;

    cout << "Celsius to Fahrenheit converter." << endl
         << "This program accepts decimals using period or comma (example 37.5 or 37,5)" << endl << endl;
    cout << "Enter temperature in Celsius: ";
    cin >> celsiusString;

    replace(celsiusString.begin(), celsiusString.end(), ',', '.');

    double celsiusDouble = stod(celsiusString);
    double fahrenheitDouble = (celsiusDouble * 9 / 5) + 32;

    cout << celsiusDouble
         << "°C is equal to "
         << fahrenheitDouble
         << "°F"
         << endl;
}

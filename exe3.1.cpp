#include <iostream>

using namespace std;

int main() {
    int first, second, third;

    cout << "Enter three integers: ";
    cin >> first;
    cin >> second;
    cin >> third;

    int sumAll = first + second + third;
    double averageAll = sumAll / 3.0;

    bool isAllPositives = first > 0 && second > 0 && third > 0;
    bool isHasEven = first % 2 == 0 || second % 2 == 0 || third % 2 == 0;

    cout << "The sum of the numbers = " << sumAll << endl;
    cout << "The average = " << averageAll << endl;
    cout << "Whether all three numbers are positive (1 = true, 0 = false) = "
         << isAllPositives << endl;
    cout << "Whether at least one number is even (1 = true, 0 = false) = "
         << isHasEven << endl;
}

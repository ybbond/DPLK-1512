#include <iostream>

using namespace std;

int main() {
    int testCases;
    cin >> testCases;

    for (int i = 0; i < testCases; i++) {
        int totalAhead = 0;
        int tiffany, current;

        cin >> tiffany;

        for (int j = 0; j < 9; j++) {
            cin >> current;

            if (current > tiffany) {
                totalAhead++;
                // bisa juga kaya gini:
                // totalAhead += 1;
                // totalAhead = totalAhead + 1;
            }
        }

        cout << totalAhead << endl;
    }

    return 0;
}

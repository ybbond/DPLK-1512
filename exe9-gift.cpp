#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int testCases;
    cin >> testCases;

    for (int test = 0; test < testCases; test = test + 1) {
        int arrayLength;
        cin >> arrayLength;

        int a[arrayLength];
        for (int i = 0; i < arrayLength; i = i + 1) {
            cin >> a[i];
        }

        // kalo diurutin dari yang tergede,
        // ada kemungkinan berhasil
        sort(a, a + arrayLength);

        // abis yang tergede taruh yang terkecil
        // biar hitungan kedua lebih efisien
        int arranged[arrayLength];
        arranged[0] = a[arrayLength - 1];

        for (int i = 1; i < arrayLength; i = i + 1) {
            arranged[i] = a[i - 1];
        }

        int score = 0;
        int minVal = arranged[0];
        int maxVal = arranged[0];

        for (int i = 0; i < arrayLength; i = i + 1) {
            if (arranged[i] < minVal) {
                minVal = arranged[i];
            }
            if (arranged[i] > maxVal) {
                maxVal = arranged[i];
            }

            score = score + (maxVal - minVal);
        }

        cout << score << endl;
    }

    return 0;
}

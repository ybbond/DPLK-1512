#include <iostream>
#include <string>

using namespace std;

int main() {
    int k, n;
    cin >> k;
    cin >> n;

    switch (k) {
        case 1: {
            string result(n, '*');
            for (int i = 0; i < n; i++) {
                cout << result << endl;
            }
            break;
        }
        case 2: {
            for (int i = 0; i < n; i++) {
                string result(i + 1, '*');
                cout << result << endl;
            }
            break;
        }
        case 3: {
            for (int i = n; i > 0; i--) {
                string result(i, '*');
                cout << result << endl;
            }
            break;
        }
    }

    return 0;
}

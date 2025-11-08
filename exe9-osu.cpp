#include <iostream>
#include <string>

using namespace std;

void constructOsuOutput(string*, int, int);

int main() {
    int testCases;
    cin >> testCases;

    for (int i = 0; i < testCases; i++) {
        int totalBeats;
        cin >> totalBeats;
        string output = "";
        for (int bi = 0; bi < totalBeats; bi++) {
            constructOsuOutput(&output, bi, totalBeats);
        }
        cout << output << endl;
    }

    return 0;
}

void constructOsuOutput(string *output, int currentBeat, int totalBeats) {
    char beats[4];
    for (int c = 0; c < 4; c++) {
        cin >> beats[c];

        if (beats[c] == '#') {
            string separator = (currentBeat > 0 ? " " : "");
            string toAdd = to_string(c + 1) + separator;
            *output = toAdd + *output;
        }
    }
}

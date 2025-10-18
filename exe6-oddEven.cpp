#include <iostream>

using namespace std;

enum Parity { EVEN, ODD };

Parity getParity(int input);

int main() {
    int testCaseCount;
    cin >> testCaseCount;

    int arrayLength, playerStart, playerEnd;

    for (int i = 0; i < testCaseCount; i++) {
        cin >> arrayLength;
        cin >> playerStart;

        Parity arrayLengthParity = getParity(arrayLength);
        int iterationStart, winner;
        int listSum = 0;

        switch (arrayLengthParity) {
            // kalau genap, berarti playerEnd adalah lawan dari playerStart
            case EVEN:
                if (playerStart == 1) {
                    playerEnd = 2;
                } else {
                    playerEnd = 1;
                }
                iterationStart = 1;
                break;
            // kalau ganjil, berarti playerEnd sama dengan playerStart
            case ODD:
                playerEnd = playerStart; // ← 1
                iterationStart = 0;
                break;
        }

        int numberList[arrayLength];

        for (int listIndex = 0; listIndex < arrayLength; listIndex++) {
            cin >> numberList[listIndex];
        }


        for (int j = iterationStart; j < arrayLength; j = j + 2) {
            listSum = listSum + numberList[j];
        }

        Parity listSumParity = getParity(listSum);

        switch (listSumParity) {
            // kalau genap, playerEnd menang
            case EVEN:
                winner = playerEnd;
                break;
            // kalau ganjil, lawan menang
            case ODD:
                if (playerEnd == 1) {
                    winner = 2;
                } else {
                    winner = 1;
                }
                break;
        }

        // kalau genap, playerEnd menang
        if (listSumParity == EVEN) {
            winner = playerEnd;
        }
        // kalau ganjil, lawan menang
        if (listSumParity == ODD) {
            if (playerEnd == 1) {
                winner = 2;
            } else {
                winner = 1;
            }
        }

        cout << winner << endl;
    }

    return 0;
}

Parity getParity(int input) {
    // return input % 2 == 0 ? EVEN : ODD;

    if (input % 2 == 0) {
        return EVEN;
    } else {
        return ODD;
    }
}

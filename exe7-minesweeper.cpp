#include <iostream>

using namespace std;

int main() {
    int rowSize, columnSize;
    int count = 1;

    const int neighborRow[]    = { -1, -1, -1,  0,  1,  1,  1,  0 };
    const int neighborColumn[] = { -1,  0,  1,  1,  1,  0, -1, -1 };

    while (cin >> rowSize >> columnSize && (rowSize > 0 && columnSize > 0)) {
        // {
        //   { '*', '.', '.', '.' },
        //   { '.', '.', '.', '.' },
        //   { '.', '*', '.', '.' },
        //   { '.', '.', '.', '.' }
        // }
        // [0][0] → [0][1], [1][0], [1][1]
        // [2][1] → [1][0], [1][1], [1][2], [2][0], [2][2], [3][0], [3][1], [3][2]
        char fields[rowSize][columnSize];
        int result[rowSize][columnSize];

        for (int r = 0; r < rowSize; r++) {
            for (int c = 0; c < columnSize; c++) {
                cin >> fields[r][c];
                result[r][c] = 0;
            }
        }

        for (int r = 0; r < rowSize; r++) {
            for (int c = 0; c < columnSize; c++) {
                if (fields[r][c] == '.') continue; // early return

                for (int i = 0; i < 8; i++) {
                    int nr = r + neighborRow[i];
                    int nc = c + neighborColumn[i];

                    if (
                      nr >= 0 &&
                      nr < rowSize &&
                      nc >= 0 &&
                      nc < columnSize &&
                      fields[nr][nc] != '*'
                    ) {
                        result[nr][nc]++;
                    }
                }
            }
        }

        cout << endl << "Field #" << count << ":" << endl;

        for (int r = 0; r < rowSize; r++) {
            for (int c = 0; c < columnSize; c++) {
                if (fields[r][c] == '*') {
                    cout << '*';
                } else {
                    cout << result[r][c];
                }
            }
            cout << endl;
        }

        cout << endl;
        count++;
    }

    return 0;
}

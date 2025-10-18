#include <iostream>

using namespace std;

int main() {
  int rowSize, columnSize;
  int count = 1;

  while (true) {
      cin >> rowSize;
      cin >> columnSize;

      if (rowSize <= 0 || columnSize <= 0) break;

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

          // kiri atas
          if (r - 1 >= 0 && c - 1 >= 0 && fields[r - 1][c - 1] != '*') {
            result[r - 1][c - 1]++;
          }

          // atas
          if (r - 1 >= 0 && fields[r - 1][c] != '*') {
            result[r - 1][c]++;
          }

          // kanan atas
          if (r - 1 >= 0 && c + 1 < columnSize && fields[r - 1][c + 1] != '*') {
            result[r - 1][c + 1]++;
          }

          // kiri
          if (c - 1 >= 0 && fields[r][c - 1] != '*') {
            result[r][c - 1]++;
          }

          // kanan
          if (c + 1 < columnSize && fields[r][c + 1] != '*') {
            result[r][c + 1]++;
          }

          // kiri bawah
          if (r + 1 < rowSize && c - 1 >= 0 && fields[r + 1][c - 1] != '*') {
            result[r + 1][c - 1]++;
          }

          // bawah
          if (r + 1 < rowSize && fields[r + 1][c] != '*') {
            result[r + 1][c]++;
          }

          // kanan bawah
          if (r + 1 < rowSize && c + 1 < columnSize && fields[r + 1][c + 1] != '*') {
            result[r + 1][c + 1]++;
          }
        }
      }

      cout << "Field #" << count << ":" << endl;

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
  }

  return 0;
}

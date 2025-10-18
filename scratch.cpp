#include <iostream>

using namespace std;

int main() {
  char array[5];
  for (int i = 0; i < 5; i++) {
    cin >> array[i];
  }

  cout << "array[0]: " << array[0] << endl;
  cout << "array[1]: " << array[1] << endl;
  cout << "array[2]: " << array[2] << endl;
  cout << "array[3]: " << array[3] << endl;
  cout << "array[4]: " << array[4] << endl;

  return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// disclaimer: dokumen ini sambil buat belajar, jadi ada beberapa approach yang dikomen
//             juga ada beberapa penjelasan atau visualisasi iterasi dan memory allocation
int main() {
    long long N;
    cin >> N;

    if (N == 1) {
        cout << "1 = 1" << endl;
        return 0;
    }

    vector<long long> faktor;

    // N = 12
    // i = 1 -> iterasi valid
    //  12 % 1 == 0 → 1 masuk ke vector
    //  1 != 12 / 1 → 12 masuk ke vector
    //  isi dari vector = [1, 12]
    // i = 2 -> iterasi valid
    //  12 % 2 == 0 → 2 masuk ke vector
    //  2 != 12 / 2 → 6 masuk ke vector
    //  isi dari vector = [1, 12, 2, 6]
    // i = 3 -> iterasi valid
    //  12 % 3 == 0 → 3 masuk ke vector
    //  3 != 12 / 3 → 4 masuk ke vector
    //  isi dari vector = [1, 12, 2, 6, 3, 4]
    // i = 4 -> iterasi tidak valid
    //       -> for loop berhenti

    for (long long i = 1; i * i <= N; i++) {
        // % → modulus (eng) / modulo (ind) operator
        if (N % i == 0) {
            faktor.push_back(i);
            if (i != N / i) faktor.push_back(N / i);
        }
    }

    // int arr[] = {5, 2, 8, 1, 9};
    // std::sort(arr, arr + n)
    // [N][N][N][N][N][N][N][N][ ][ ][ ]..........[vec][vec][length][capabilities][1][5][2][2][5][5][8][8][9][9][ ][ ]

    sort(faktor.begin(), faktor.end());

    // i++ SAMA DENGAN i += 1 SAMA DENGAN i = i + 1

    // // APPROACH 1, multiple for loop
    // long long hasil = 0;
    // for (size_t i = 0; i < faktor.size(); i++) {
    //     // if (i % 2 == 0) hasil += faktor[i];
    //     // else hasil -= faktor[i];
    //     if (i % 2 == 0) {
    //       hasil = hasil + faktor[i];
    //     } else {
    //       hasil = hasil - faktor[i];
    //     }
    // }
    //
    // for (size_t i = 0; i < faktor.size(); i++) {
    //     cout << faktor[i];
    //     if (i != faktor.size() - 1) {
    //         if (i % 2 == 0) cout << " - ";
    //         else cout << " + ";
    //     }
    // }
    // cout << " = " << hasil << endl;

    // // APPROACH 2: single for loop, kalkulasi dan string concat terpisah
    // long long hasil = 0;
    // string output = "";
    // for (long long i = 0; i < faktor.size(); i++) {
    //     if (i % 2 == 0) hasil += faktor[i];
    //     else hasil -= faktor[i];

    //     output = output + to_string(faktor[i]);
    //     if (i != faktor.size() - 1) {
    //         if (i % 2 == 0) output = output + " - ";
    //         else output = output + " + ";
    //     }
    // }
    // output = output + " = " + to_string(hasil);
    // cout << output << endl;

    // APPROACH 3: single for loop, kalkulasi dan string concatenation gabung
    long long hasil = 0;
    string output = "";
    for (size_t i = 0; i < faktor.size(); i++) {
        output = output + to_string(faktor[i]);
        if (i % 2 == 0) {
            hasil = hasil + faktor[i];
            if (i != faktor.size() - 1) output = output + " - ";
        } else {
            hasil = hasil - faktor[i];
            if (i != faktor.size() - 1) output = output + " + ";
        }
    }
    output = output + " = " + to_string(hasil);
    cout << output << endl;

    return 0;
}

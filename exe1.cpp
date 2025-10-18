#include <iostream>

int main() {
    // this is assuming that the tab output across machine is consistent
    // which according to this stack overflow is at 8 whitespaces
    //     https://stackoverflow.com/questions/13094690/how-many-spaces-for-tab-character-t/13094769#13094769
    //
    // I've tried consulting on other students' machine and this far they are consistent.
    // I hope that the tab stop on Mr. Kelvin Wiriyatama's machine is also at 8 whitespaces :-)
    std::cout << "Nama\t\t: Yohanes Bandung Bondowoso\nNIM\t\t: 01085250015\nAngkatan\t: 2025" << std::endl;
    return 0;
}

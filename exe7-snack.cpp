#include <iostream>

using namespace std;

int main() {
    int vikoMoney, snackPrice, sachetRequirement;
    cin >> vikoMoney >> snackPrice >> sachetRequirement;

    int sum = 0;
    int vikoSachet = 0;

    // urutan:
    // 1. beli, dapat snack dan langsung dimakan jadi sachet, simpan kembalian
    // 2. totalin dulu berapa yang udah dimakan
    // 3. sachet ditukar sesuai syarat, sisanya masih disimpan
    // 4. snack bonus langsung dimakan, sachet gabungkan ke yang udah ada tersimpan
    // 5. totalin yang dimakan di step 4
    // 6. ulangi step 3 - 5 hingga sachet habis, atau di bawah syarat

    do {
        if (vikoMoney >= snackPrice) {
            // dapat bungkus dari yang terbeli
            vikoSachet = vikoMoney / snackPrice;
            // simpan kembalian
            vikoMoney = vikoMoney % snackPrice;
            // tambah total ke yang udah pernah dia dapat
            sum += vikoSachet;
        }

        if (vikoSachet >= sachetRequirement) {
            // tukar sachet sejumlah memenuhi syarat
            int newSachet = vikoSachet / sachetRequirement;
            // sachet sisa tak tertukar, ditambah sachet baru
            vikoSachet = (vikoSachet % sachetRequirement) + newSachet;
            // tambah total ke yang udah pernah dia dapat
            sum += newSachet;
        }
    } while (vikoMoney >= snackPrice || vikoSachet >= sachetRequirement);

    cout << sum << endl;

    return 0;
}

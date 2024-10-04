#include <iostream>
using namespace std;

int kendaraan(int kapasitasKendaraan, int jumlahPenumpang) {
    int jumlah;
    jumlah = jumlahPenumpang / kapasitasKendaraan;
    if (jumlahPenumpang % kapasitasKendaraan > 0) {
        jumlah++;
    }
    return jumlah;
}

int main() {
    int kapKendaraan, jumPenumpang, banyakKendaraan;
    cout << "Masukan kapasitas kendaraan: ";
    cin >> kapKendaraan;
    cout << "Masukan jumlah penumpang: ";
    cin >> jumPenumpang;
    banyakKendaraan = kendaraan(kapKendaraan, jumPenumpang);
    cout << "Banyak kendaraan yang disewa: " << banyakKendaraan << endl;
    return 0;
}
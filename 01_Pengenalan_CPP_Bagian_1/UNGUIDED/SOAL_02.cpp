#include <iostream>
#include <string>

using namespace std;

string angkaKeKata(int angka) {
    const string satuan[] = {"satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan"};
    const string belasan[] = {"sepuluh", "sebelas", "dua belas", "tiga belas", "empat belas", "lima belas", "enam belas", "tujuh belas", "delapan belas", "sembilan belas"};
    const string puluhan[] = {"dua puluh", "tiga puluh", "empat puluh", "lima puluh", "enam puluh", "tujuh puluh", "delapan puluh", "sembilan puluh"};

    if (angka < 0 || angka > 100) {
        return "Angka tidak valid";
    }
    if (angka == 0) {
        return "nol";
    }
    if (angka < 10) {
        return satuan[angka - 1]; 
    }
    if (angka < 20) {
        return belasan[angka - 10];
    }

    int puluhanAngka = angka / 10 - 2;
    int satuanAngka = angka % 10;

   return satuanAngka > 0 ? puluhan[puluhanAngka] + " " + satuan[satuanAngka - 1] : puluhan[puluhanAngka];

}

int main() {
    int angka;
    cout << "Masukkan angka (0-100): ";
    cin >> angka;
    cout << angka << ": " << angkaKeKata(angka) << endl;

    return 0;
}

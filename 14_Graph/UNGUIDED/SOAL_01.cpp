#include <iostream>
#include <vector>
using namespace std;

int main() {
    int jumlahSimpul; 
    cout << "Silakan masukan jumlah simpul: ";
    cin >> jumlahSimpul;

    vector<string> kota(jumlahSimpul);
    cout << "Silakan masukan nama simpul: " << endl;
    for (int i = 0; i < jumlahSimpul; i++) {
        cout << "Simpul " << i + 1 << " : ";
        cin >> kota[i];
    }

    vector<vector<int>> bobot(jumlahSimpul, vector<int>(jumlahSimpul));

    cout << "Silakan masukkan bobot antar simpul: " << endl;
    for (int i = 0; i < jumlahSimpul; i++) {
        for (int j = 0; j < jumlahSimpul; j++) {
            cout << kota[i] << "--> " << kota[j] << " = ";
            cin >> bobot[i][j];
        }
    }

    cout << "\n         "; 
    for (int i = 0; i < jumlahSimpul; i++) {
        cout << kota[i] << "    "; 
    }
    cout << endl;

    for (int i = 0; i < jumlahSimpul; i++) {
        cout << kota[i]; 
        for (int j = 0; j < jumlahSimpul; j++) {
            cout << "      " << bobot[i][j]; 
        }
        cout << endl;
    }

    return 0;
}

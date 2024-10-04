#include <iostream>
#include <conio.h>
#include <stdlib.h>
#define MAX 5
using namespace std;

int maks3(int a, int b, int c);

int main() {
    // 1
    // int x, y;
    // int *px;
    // x = 87;
    // px = &x;
    // y = *px;

    // cout << "Alamat x: " << &x << endl;
    // cout << "Isi px: " << px << endl;
    // cout << "Isi x: " << x << endl;
    // cout << "Nilai yang ditunjuk px: " << *px << endl;
    // cout << "Nilai y: " << y << endl;
    // getch();

    // return 0;


    // 2
    // int i, j;
    // float nilai_total, rata_rata;
    // float nilai[MAX];
    
    // static int nilai_tahun[MAX][MAX]= {
    //     {0, 2, 2, 0, 0},
    //     {0, 1, 1, 1, 0},
    //     {0, 3, 3, 3, 0},
    //     {4, 4, 0, 0, 4},
    //     {5, 0, 0, 0, 5}
    // };

    // // Inisialisasi array dua dimensi
    // for (i = 0; i < MAX; i++ ) {
    //     cout << "Masukan nilai ke- " << i + 1 << endl;
    //     cin >> nilai[i];
    // }
    // cout << "\ndata nilai siswa :\n";

    // // Menampilkan array satu dimensi
    // for (i = 0; i < MAX; i++) {
    //     cout << "Nilai ke-" << i + 1 << "=" << nilai[i] << endl;
    // }   
    // cout << "\nnilai tahunan: \n";

    // // Menampilkan array dua demensi
    // for (i = 0; i < MAX; i++) {
    //     for (j = 0; j < MAX; j++) {
    //         cout << nilai_tahun[i][j];
    //     }
    //     cout << "\n";
    // }

    // getch();
    // return 0;


    

    system("cls");
    int x, y, z;
    cout << "Masukan nilai bilangan ke-1: ";
    cin >> x;
    cout << "Masukan nilai bilangan ke-2: ";
    cin>> y;
    cout << "Masukan nilai bilangan ke-3: ";
    cin >> z;

    cout << "Nilai maksimumnya adalah: " << maks3(x, y, z);
    getche();
    return 0;
}

int maks3(int a, int b, int c) {
    int temp_max = a;
    if (b > temp_max) {
        temp_max = b;
    }
    if (c > temp_max) {
        temp_max = c;
    }

    return (temp_max);
}
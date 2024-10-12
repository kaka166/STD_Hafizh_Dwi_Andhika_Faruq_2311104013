#include <iostream>
using namespace std;

void tampilkanArray(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void tukarPosisiArray(int arr1[3][3], int arr2[3][3], int baris, int kolom) {
    int temp = arr1[baris][kolom];
    arr1[baris][kolom] = arr2[baris][kolom];
    arr2[baris][kolom] = temp;
}

void tukarNilaiPointer(int *ptr1, int *ptr2) {
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

int main() {
    int array1[3][3] = {{2, 7, 3}, {1, 9, 3}, {4, 5, 9}};
    int array2[3][3] = {{4, 3, 2}, {5, 6, 9}, {1, 2, 1}};
    
    int a = 1, b = 2;
    int *ptr1 = &a;
    int *ptr2 = &b;

    cout << "Array 1 sebelum tukar: " << endl;
    tampilkanArray(array1);
    cout << "Array 2 sebelum tukar: " << endl;
    tampilkanArray(array2);

    tukarPosisiArray(array1, array2, 2, 1);
    cout << "Array 1 setelah tukar di posisi 2,1: " << endl;
    tampilkanArray(array1);
    cout << "Array 2 setelah tukar di posisi 2,1: " << endl;
    tampilkanArray(array2);

    cout << "Nilai sebelum tukar ptr1 = " << *ptr1 << ", ptr2 = " << *ptr2 << endl;
    tukarNilaiPointer(ptr1, ptr2);
    cout << "Nilai setelah tukar ptr1 = " << *ptr1 << ", ptr2 = " << *ptr2 << endl;

    return 0;
}

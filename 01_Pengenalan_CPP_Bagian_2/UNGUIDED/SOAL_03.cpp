#include <iostream>
using namespace std;

int main() {
    int size;
    
    cout << "Masukkan jumlah elemen dalam array: ";
    cin >> size;

    int* arr = new int[size];
    cout << "Masukkan elemen array:\n";
    for (int i = 0; i < size; i++) {
        cout << "Elemen " << (i + 1) << ": ";
        cin >> arr[i];
    }

    int max = arr[0], min = arr[0];
    double sum = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
        sum += arr[i];
    }

    cout << "Nilai maksimum: " << max << endl;
    cout << "Nilai minimum: " << min << endl;
    cout << "Nilai rata-rata: " << (sum / size) << endl;

    delete[] arr; // Dealokasi memori
    return 0;
}

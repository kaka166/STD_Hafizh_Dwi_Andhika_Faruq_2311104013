#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    int nim;
    string nama;
    Mahasiswa* next;
};

void tambahMahasiswa(Mahasiswa*& head, int nim, string nama) {
    Mahasiswa* mahasiswa = new Mahasiswa();
    mahasiswa->nim = nim;
    mahasiswa->nama = nama;
    mahasiswa->next = NULL;

    if (head == NULL) {
        head = mahasiswa;
    } else {
        Mahasiswa* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = mahasiswa;
    }
}

void cariMahasiswa(Mahasiswa* head, int nim) {
    Mahasiswa* temp = head;
    while (temp != NULL) {
        if (temp->nim == nim) {
            cout << "Mahasiswa ditemukan: " << temp->nama << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Mahasiswa dengan NIM " << nim << " tidak ditemukan" << endl;
}

void tampilkanMahasiswa(Mahasiswa* head) {
        Mahasiswa* temp = head;
    if (temp == NULL) {

        cout << "Tidak ada mahasiswa" << endl;
    } else {
        while (temp != NULL) {
            cout << "NIM: " << temp->nim << ", Nama: " << temp->nama << endl;
            temp = temp->next;
        }
    }
}

int main() {
    Mahasiswa* head = NULL;

    tambahMahasiswa(head, 23111040, "Abdul");
    tambahMahasiswa(head, 23111050, "Supri");
    tambahMahasiswa(head, 23111060, "Parto");

    int cariNim;
    cout << "Masukan NIM yang ingin dicari: ";
    cin >> cariNim;
    cariMahasiswa(head, cariNim);

    cout << "Daftar mahasiswa dalam list: " << endl;
    tampilkanMahasiswa(head);

    return 0;
}
#include <iostream>
#include <string>
using namespace std;

struct Proyek {
    string namaProyek;
    int durasi;
    Proyek* nextProyek;
};

struct Pegawai {
    string namaPegawai;
    string idPegawai;
    Proyek* proyekHead;
    Pegawai* nextPegawai;
};

void tambahPegawai(Pegawai*& head, const string& nama, const string& id) {
    Pegawai* pegawai = new Pegawai{nama, id, nullptr, head};
    head = pegawai;
}

void tambahProyek(Pegawai* head, const string& id, const string& namaProyek, int durasi) {
    while (head && head->idPegawai != id) {
        head = head->nextPegawai;
    }

    if (head) {
        Proyek* proyek = new Proyek{namaProyek, durasi, head->proyekHead};
        head->proyekHead = proyek;
    }
}

void hapusProyek(Pegawai* head, const string& id, const string& namaProyek) {
    while (head && head->idPegawai != id) {
        head = head->nextPegawai;
    }

    if (head) {
        Proyek* curr = head->proyekHead;
        Proyek* prev = nullptr;
        
        while (curr && curr->namaProyek != namaProyek) {
            prev = curr;
            curr = curr->nextProyek;
        }

        if (curr) {
            if (prev) {
                prev->nextProyek = curr->nextProyek;
            } else {
                head->proyekHead = curr->nextProyek;
            }
            delete curr;
        }
    }
}

void tampilkanData(Pegawai* head) {
    while (head) {
        cout << "Pegawai: " << head->namaPegawai << ", ID: " <<  head->idPegawai << endl; 

        Proyek* proyek = head->proyekHead;
        while (proyek) {
            cout << "Proyek : " << proyek->namaProyek << ", Durasi: " << proyek->durasi << " bulan" << endl;
            proyek = proyek->nextProyek;
        }
        head = head->nextPegawai;
    }
}

int main() {
    Pegawai* listPegawai = nullptr;

    tambahPegawai(listPegawai, "Andi", "P001");
    tambahPegawai(listPegawai, "Budi", "P002");
    tambahPegawai(listPegawai, "Citra", "P003");

    tambahProyek(listPegawai, "P001", "Aplikasi Mobile", 12);
    tambahProyek(listPegawai, "P002", "Sistem Akuntansi", 8);
    tambahProyek(listPegawai, "P003", "E-Commerce", 10);

    tambahProyek(listPegawai, "P001", "Analisis Data", 6);

    hapusProyek(listPegawai, "P001", "Aplikasi Mobile");

    cout << "Data Pegawai dan Proyek: " << endl;
    tampilkanData(listPegawai);

    return 0;
}
#include <iostream>
#include <string>
using namespace std;

struct Buku {
    string judulBuku;
    string tglPengembalian;
    Buku* nextBuku;
};

struct Anggota {
    string namaAnggota;
    string idAnggota;
    Buku* bukuHead;
    Anggota* nextAnggota;
};

void tambahAnggota(Anggota*& head, const string& nama, const string& id) {
    Anggota* anggota = new Anggota{nama, id, nullptr, head};
    head = anggota;
}

void tambahBuku(Anggota* head, const string& id, const string& judulBuku, const string& tglPengembalian) {
    while (head && head->idAnggota != id) {
        head = head->nextAnggota;
    }

    if (head) {
        Buku* bukuBaru = new Buku{judulBuku, tglPengembalian, head->bukuHead};
        head->bukuHead = bukuBaru;
    }
}


void hapusAnggota(Anggota*& head, const string& id) {
    Anggota* curr = head;
    Anggota* prev = nullptr;

    while (curr && curr->idAnggota != id) {
        prev = curr;
        curr = curr->nextAnggota;
    }

    if (curr) {
        if (prev) {
            prev->nextAnggota = curr->nextAnggota;
        } else {
            head = curr->nextAnggota;
        }

        Buku* buku = curr->bukuHead;
        while (buku) {
            Buku* temp = buku;
            buku = buku->nextBuku;
            delete temp;
        }
        delete curr;
    }
}

void tampilkanData(Anggota* head) {
    while (head) {
        cout << "Anggota: " << head->namaAnggota << ", ID: " << head->idAnggota <<endl; 
        Buku* buku = head->bukuHead;
        while (buku) {
            cout << "Buku: " << buku->judulBuku << ", Pengembalian: " << buku->tglPengembalian << endl;
            buku = buku->nextBuku;
        }
        head = head->nextAnggota;
    }
}

int main() {
    Anggota* listAnggota = nullptr;

    tambahAnggota(listAnggota, "Rani", "A001");
    tambahAnggota(listAnggota, "Dito", "A002");
    tambahAnggota(listAnggota, "Vina", "A003");

    tambahBuku(listAnggota, "A001", "Pemrograman C++", "01/12/2024");
    tambahBuku(listAnggota, "A002", "Algoritma Pemrograman", "15/12/2024");

    tambahBuku(listAnggota, "A001", "Struktur Data", "10/12/2024");

    hapusAnggota(listAnggota, "A002");

    cout << "Data Anggota dan Buku yang dipinjam: " << endl;
    tampilkanData(listAnggota);

    return 0;
}
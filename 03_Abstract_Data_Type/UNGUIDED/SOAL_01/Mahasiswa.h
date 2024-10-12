#ifndef MAHASISWA_H
#define MAHASISWA_H

#include <string>

struct Mahasiswa {
    std::string nama;
    int nim;
    int uts;
    int uas;
    int tugas;
    double nilaiAkhir;
    };

    double hitungNilaiAkhir(int uts, int uas, int tugas);

#endif
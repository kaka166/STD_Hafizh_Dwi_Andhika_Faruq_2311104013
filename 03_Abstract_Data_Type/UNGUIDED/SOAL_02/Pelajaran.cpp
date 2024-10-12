#include <iostream>
#include "Pelajaran.h"
using namespace std;

Pelajaran createPelajaran(std::string namaMapel, std::string kodeMapel) {
    Pelajaran pelajaran;
    pelajaran.namaMapel = namaMapel;
    pelajaran.kodemapel = kodeMapel;
    return pelajaran;
}

void tampilPelajaran(Pelajaran pelajaran) {
    cout << "Nama Pelajaran: " << pelajaran.namaMapel << endl;
    cout << "Kode Mapel: " << pelajaran.kodemapel << endl; 
}
#ifndef PELAJARAN_H
#define PELAJARAN_H

#include <string>

struct Pelajaran {
    std::string namaMapel;
    std::string kodemapel;
};

Pelajaran createPelajaran(std::string namaMapel, std::string kodeMapel);
void tampilPelajaran(Pelajaran pelajaran);

#endif
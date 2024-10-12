#include <iostream>
#include "Pelajaran.h"
using namespace std;

int main() {
    string namaMapel = "Strukur Data";
    string kodeMapel = "STD";

    Pelajaran pelajaran = createPelajaran(namaMapel, kodeMapel);
    tampilPelajaran(pelajaran);
    
    return 0;
}
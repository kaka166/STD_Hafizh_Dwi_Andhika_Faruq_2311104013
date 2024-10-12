#include <iostream>
#include "mahasiswa.h"
using namespace std;

void inputMhs(mahasiswa &m) {
    cout << "Input nama: ";
    cin >> m.nim;
    cout << "Input nilai 1: ";
    cin >> m.nilai1;
    cout << "Input nilai 2: ";
    cin >> m.nilai2;
}

float rata2(mahasiswa m){ 
  return (m.nilai1+m.nilai2)/2; 
} 
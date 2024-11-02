#include <iostream>
#include "stack.h" 
using namespace std;

int main() {
    stack S;
    createStack(S);
    int lastDigitNIM = 3;
    int mod = lastDigitNIM % 4;

    if (mod == 0) {
        push(S, 'A');
        push(S, 'Y');
        push(S, 'A');
        push(S, 'J');
        push(S, 'B');
        push(S, 'A');
        push(S, 'L');
        push(S, 'F');
        push(S, 'I');
    } else if (mod == 1) {
        push(S, 'G');
        push(S, 'N');
        push(S, 'U');
        push(S, 'D');
        push(S, 'N');
        push(S, 'A');
        push(S, 'B');
        push(S, 'O');
        push(S, 'L');
        push(S, 'A');
        push(S, 'H');
    } else if (mod == 2) {
        push(S, 'I');
        push(S, 'R');
        push(S, 'I');
        push(S, 'D');
        push(S, 'A');
        push(S, 'Y');
        push(S, 'A');
        push(S, 'C');
        push(S, 'R');
        push(S, 'E');
        push(S, 'P');
    } else if (mod == 3) {
        push(S, 'A');
        push(S, 'T');
        push(S, 'A');
        push(S, 'D');
        push(S, 'R');
        push(S, 'U');
        push(S, 'T');
        push(S, 'K');
        push(S, 'U');
        push(S, 'R');
        push(S, 'T');
        push(S, 'S');
    }


    cout << "Isi awal Stack:" << endl;
    printInfo(S);

    cout << "Isi setelah pop:" << endl;
    for (int i = 0; i < 8; i++) {  
        pop(S);
    }
    printInfo(S);

    return 0;
}


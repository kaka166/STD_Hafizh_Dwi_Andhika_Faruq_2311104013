#include <iostream>
#include "stack.h"
using namespace std;

void createStack(stack &S) {
    S.Top = 0;
}

bool isEmpty(stack S) {
    return S.Top == 0;
}

bool isFull(stack S) {
    return S.Top == 15;
}

void push(stack &S, infotype x) {
    if (!isFull(S)) {
        S.Top++;
        S.info[S.Top - 1] = x;
    }
}

infotype pop(stack &S) {
    if (!isEmpty(S)) {
        infotype x = S.info[S.Top - 1];
        S.Top--;
        return x;
    }
    return '\0';
}

void printInfo(stack S) {
    for (int i = S.Top - 1; i >= 0; i--) {
        cout << S.info[i] << " ";
    }
    cout << endl;
}

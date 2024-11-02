#include <iostream>
#include <stack>
using namespace std;

bool isPalindrome(const string& kalimat) {
    stack<char> stackKarakter;
    string kalimatString = "";

    for (char karakter : kalimat) {
        if ((karakter >= 'A' && karakter <= 'Z') || (karakter >= 'a' && karakter <= 'z')) {
            if (karakter >= 'A' && karakter <= 'Z') {
                karakter += 32;
            }
            kalimatString += karakter;
        }
    }

    for (char karakter : kalimatString) {
        stackKarakter.push(karakter);
    }

    for (char karakter : kalimatString) {
        if (karakter != stackKarakter.top()) {
            return false;
        }
        stackKarakter.pop();
    }

    return true;
}

int main() {
    string kalimatInput;
    cout << "Masukkan kalimat: ";
    getline(cin, kalimatInput);

    if (isPalindrome(kalimatInput)) {
        cout << "Kalimat tersebut adalah palindrom." << endl;
    } else {
        cout << "Kalimat tersebut bukan palindrom." << endl;
    }

    return 0;
}

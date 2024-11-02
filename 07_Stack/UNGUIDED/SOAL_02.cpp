#include <iostream>
#include <stack>
using namespace std;

string reverseWord(const string& word) {
    stack<char> stackChar;
    string reversedWord;

    for (char ch : word) {
        stackChar.push(ch);
    }
    
    while (!stackChar.empty()) {
        reversedWord += stackChar.top();
        stackChar.pop();
    }

    return reversedWord;
}

void reverseSentence(const string& sentence) {
    stack<string> stackString;
    string word;
    
    for (int i = 0; i <= sentence.length(); ++i) {
        if (i == sentence.length() || sentence[i] == ' ') { 
            if (!word.empty()) { 
                stackString.push(reverseWord(word));
                word.clear(); 
            }
        } else {
            word += sentence[i]; 
        }
    }

    while (!stackString.empty()) {
        cout << stackString.top() << " ";
        stackString.pop();
    }
    cout << endl;
}

int main() {
    string kalimat;
    cout << "Masukan kalimat: ";
    getline(cin, kalimat);

    cout << "Kalimat setelah dibalik: ";
    reverseSentence(kalimat);

    return 0;
}

#include <iostream>
#include <string>
using namespace std;

struct Node {
    string nama;
    string NIM;
    Node* next;
};

Node* head = nullptr;
Node* tail = nullptr;

bool isEmpty() {
    return head == nullptr;
}

void enqueueAntrian(string nama, string NIM) {
    Node* node = new Node();
    node->nama = nama;
    node->NIM = NIM;
    node->next = nullptr;

    if (isEmpty()) {
        head = tail = node;
    } else {
        tail->next = node;
        tail = node;
    }
}

void dequeueAntrian() {
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        Node* temp = head;
        head = head->next;
        delete temp;
        if (head == nullptr) {
            tail = nullptr;
        }
    }
}

void viewQueue() {
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        cout << "Data antrian mahasiswa:" << endl;
        Node* temp = head;
        int count = 1;
        while (temp != nullptr) {
            cout << count++ << ". Nama: " << temp->nama << ", NIM: " << temp->NIM << endl;
            temp = temp->next;
        }
    }
}

void clearQueue() {
    while (!isEmpty()) {
        dequeueAntrian();
    }
    cout << "Antrian dikosongkan" << endl;
}

int main() {
    enqueueAntrian("Andi", "210001");
    enqueueAntrian("Maya", "210002");
    viewQueue();
    dequeueAntrian();
    viewQueue();
    clearQueue();
    viewQueue();
    return 0;
}

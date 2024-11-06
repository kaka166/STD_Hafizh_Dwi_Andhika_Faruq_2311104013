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
        Node* current = head;
        Node* previous = nullptr;

        while (current != nullptr && current->NIM < NIM) {
            previous = current;
            current = current->next;
        }

        if (previous == nullptr) {
            node->next = head;
            head = node;
        } else {
            node->next = current;
            previous->next = node;
            if (current == nullptr) {
                tail = node;
            }
        }
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
    int choice;
    string nama, NIM;

    do {
        cout << "1. Tambah Mahasiswa" << endl;
        cout << "2. Hapus Mahasiswa" << endl;
        cout << "3. Lihat Antrian" << endl;
        cout << "4. Kosongkan Antrian" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Masukkan Nama: ";
                cin.ignore();
                getline(cin, nama);
                cout << "Masukkan NIM: ";
                cin >> NIM;
                enqueueAntrian(nama, NIM);
                break;
            case 2:
                dequeueAntrian();
                break;
            case 3:
                viewQueue();
                break;
            case 4:
                clearQueue();
                break;
            case 5:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
        }
    } while (choice != 5);
    return 0;
}

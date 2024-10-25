#include <iostream>
#include <string>
using namespace std;

struct Node {
    int idBuku;
    string judulBuku;
    string penulisBuku;
    Node* next;
    Node* prev;
};

void insertLast(Node*& head, int idBuku, string judulBuku, string penulisBuku) {
    Node* node = new Node();   
    node->idBuku = idBuku;
    node->judulBuku = judulBuku;
    node->penulisBuku = penulisBuku;
    node->next = NULL;

    if (head == NULL) {
        node->prev = NULL;
        head = node;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = node;
    node->prev = temp;
}

void displayBookForward(Node* head) {
    Node* temp = head;
    cout << "Daftar buku dari awal ke akhir: " << endl;
    while (temp != NULL) {
        cout << "ID: " << temp->idBuku << ", Judul: " << temp->judulBuku << ", Penulis Buku: " << temp->penulisBuku << endl;
        temp = temp->next;
    }
}

void displayBookBackward(Node* head) {
    if (head == NULL) {
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    cout << "Daftar buku dari akhir ke awal: " << endl;
    while (temp != NULL) {
        cout << "ID: " << temp->idBuku << ", Judul: " << temp->judulBuku << ", Penulis Buku: " << temp->penulisBuku << endl;
        temp = temp->prev;
    }
}

int main() {
    Node* head = NULL;
    int idBuku;
    string judulBuku, penulisBuku;

    for (int i = 0; i < 5; i++) {
        cout << "Masukan informasi buku ke-" << i+1 << endl;
        cout << "ID Buku: ";
        cin >> idBuku;
        cin.ignore();
        cout << "Judul Buku: ";
        getline(cin, judulBuku);
        cout << "Penulis Buku: ";
        getline(cin, penulisBuku);

        insertLast(head, idBuku, judulBuku, penulisBuku);
    }

    displayBookForward(head);
    displayBookBackward(head);

    return 0;
}
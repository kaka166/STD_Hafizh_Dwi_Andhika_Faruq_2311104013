#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

void insertFirst_2311104013(Node*& head, int value) {
    Node* node = new Node();
    node->data = value;
    node->next = head;
    node->prev = NULL;

    if (head != NULL) {
        head->prev = node;
    }
    head = node;
}

void insertLast_2311104013(Node*& head, int value) {
    Node* node = new Node();
    node->data = value;
    node->next = NULL;
    node->prev = NULL;

    if (head == NULL) {
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

void displayList_2311104013(Node* head) {
    Node* temp = head;
    cout << "Daftar Anggota List: ";
    while (temp != NULL) {
        cout << temp->data;
        if (temp->next != NULL) {
            cout << " <-> ";
        }
        temp = temp->next;
    }
    cout << endl;
}


int main() {
    Node* head = NULL;
    int value;

    cout << "Masukan elemen pertama: ";
    cin >> value;
    insertFirst_2311104013(head, value);

    cout << "Masukan elemen kedua di awal: ";
    cin >> value;
    insertFirst_2311104013(head, value);

    cout << "Masukan elemen ketiga di akhir: ";
    cin >> value;
    insertLast_2311104013(head, value);

    displayList_2311104013(head);

    return 0;
}
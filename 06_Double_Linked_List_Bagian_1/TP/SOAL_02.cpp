#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

void insertLast_2311104013(Node*& head, int value) {
    Node* node = new Node();
    node->data = value;
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

void deleteFirst_2311104013(Node*& head) {
    Node* temp = head;
    head = head->next;

    if (head != NULL) {
        head->prev = NULL;
    }

    delete temp;
}

void deleteLast_2311104013(Node*& head) {
    Node* temp = head;
    if (temp->next == NULL) {
        delete temp;
        head = NULL;
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->prev->next = NULL;
    delete temp;
}

void displayList_2311104013(Node* head) {
    Node* temp = head;
    cout << "Daftar Anggota List setelah dihapus: ";
    while (temp != NULL) {
        cout << temp->data;
        if (temp->next != NULL) {
            cout << " <->";
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
    insertLast_2311104013(head, value);
    
    cout << "Masukan elemen kedua di akhir: ";
    cin >> value;
    insertLast_2311104013(head, value);

    cout << "Masukan elemen ketiga di akhir: ";
    cin >> value;
    insertLast_2311104013(head, value);


    deleteFirst_2311104013(head);
    deleteLast_2311104013(head);

    displayList_2311104013(head); 

    return 0;
}
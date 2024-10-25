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

void displayForward_2311104013(Node* head) {
    Node* temp = head;
    cout << "Daftar elemen dari depan ke belakang: ";
    while (temp != NULL) {
        cout << temp->data;
        if (temp->next != NULL) {
            cout << " <-> ";
        }
        temp = temp->next;
    }
    cout << endl;
}

void displayBackward_2311104013(Node* head) {
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    cout << "Daftar elemen dari belakang ke depan: ";
    while (temp != NULL) {
        cout << temp->data;
        if (temp->prev != NULL) {
            cout << " <-> ";
        }
        temp = temp->prev;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;
    int value;

    for (int i = 0; i < 4; i++) {
        cout << "Masukan elemen ke-" << i+1 << ": ";
        cin >> value;
        insertLast_2311104013(head, value);
    }

    displayForward_2311104013(head);
    displayBackward_2311104013(head);

    return 0;
}
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

void tambahNode_2311104013(Node*& head, int value) {
    Node* node = new Node();
    node->data = value;
    node->next = NULL;

    if (head == NULL) {
        head = node;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = node;
    }
}

void searchElement_2311104013(Node* head, int i) {
    Node* current = head;
    int position = 1;

    while (current != NULL && current->data != i) {
        current = current->next;
        position++;
    }

    if (current != NULL && current->data == i) {
        cout << "Elemen ditemukan pada alamat: " << current << " dan posisi: urutan ke- " << position << endl;
    } else {
        cout << "Elemen dengan nilai: " << i << " tidak ada dalam list" << endl;
    }
}

int main() {
    Node* head = nullptr;
    int value;

    for (int i = 0; i < 6; i++) {
        cout << "Masukan elemen ke-" << i+1 << ": ";
        cin >> value;
        tambahNode_2311104013(head, value);
    }

    int cariElemen;
    cout << "Masukan elemen yang ingin dicari: ";
    cin >> cariElemen;
    searchElement_2311104013(head, cariElemen);

    return 0;
}
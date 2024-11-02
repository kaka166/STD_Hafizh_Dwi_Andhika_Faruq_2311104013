#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertSorted_2311104013(Node*& head, Node* node) {
    Node* Q = head;
    Node* prev = NULL;
    bool found = false;

    while (Q != NULL&& !found) {
        if (Q->data > node->data) {
            found = true;
        } else {
            prev = Q;
            Q = Q->next;
        }
    }

    if (prev == NULL) {
        node->next = head;
        head = node;
    } else if (Q == NULL) {
        prev->next = node;
        node->next = NULL;
    } else {
        prev->next = node;
        node->next = Q;
    }
}

void displayList_2311104013(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;
    int value;

    for (int i = 0; i < 4; i++) {
        cout << "Elemen ke-" << i+1 << ": ";
        cin >> value;

        Node* node = new Node();
        node->data = value;
        node->next = NULL;


        insertSorted_2311104013(head, node);
    }

    cout << "List setelah diurutkan: ";
    displayList_2311104013(head);

    return 0;
}
#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

void printList(Node* head){
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr){
            cout << "->";
        }
        temp = temp->next;
    }
    cout << endl;
}

void insertFront(Node*& head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void insertBack(Node*& head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        return;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = newNode;
}

int main() {
    Node* head = nullptr;

    insertFront(head,10);

    insertBack(head, 20);

    insertFront(head, 5);

    cout << "isi linked list = ";
    printList(head);

    return 0;
}
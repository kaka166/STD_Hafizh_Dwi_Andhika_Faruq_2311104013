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

void searchNode(Node* head, int value) {
    Node* temp = head;
    bool found = false;
    while (temp != nullptr) {
        if (temp->data == value) {
            found = true;
            break;
        }
        temp = temp->next;
    }

    if (found) {
        cout << "Node dengan nilai " << value << " ditemukan." << endl;
    } else {
        cout << "Node dengan nilai " << value << " tidak ditemukan." << endl;
    }
}

int countLength(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

int main() {
    Node* head = nullptr;

    insertFront(head,10);

    insertBack(head, 20);

    insertFront(head, 5);

    searchNode(head, 20);

    int length = countLength(head);
    cout << "Panjang linked list: " << length << endl;

    return 0;
}
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;        
};

void insert(Node*& head, int value) {
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

void bubbleSortList(Node* head) {
    bool swapped;
    Node* current;
    Node* lastSorted = NULL;

    if (head == NULL) {
        return;
    }

    do {
        swapped = false;
        current = head;

        while (current->next != lastSorted) {
            if (current->data > current->next->data) {
                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = true;
            }
            current = current->next;
        }
        lastSorted = current;
    } while (swapped);
}

void displayList(Node* head) {
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

    for (int i = 0; i < 5; i++) {
        cout << "Elemen ke-" << i+1 << ": ";
        cin >> value;
        insert(head, value);
    }
    
    cout << "List sebelum diurutkan: ";
    displayList(head);

    bubbleSortList(head);

    cout << "List setelah diurutkan: ";
    displayList(head);
    
    return 0;
}
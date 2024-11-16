#include <iostream>
using namespace std;

struct Pohon {
    int data;
    Pohon *left, *right, *parent;
};

Pohon *root, *baru;

void init() {
    root = NULL;
}

bool isEmpty() {
    return root == NULL;
}

void buatNode(int data) {
    if (isEmpty()) {
        root = new Pohon{data, NULL, NULL, NULL};
        cout << "\nNode " << data << " berhasil dibuat jadi root" << endl;
    } else {
        cout << "\nPohon sudah dibuat." << endl;
    }
}

Pohon *insertLeft(int data, Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree dulu." << endl;
        return NULL;
    }

    if (node->left != NULL) {
        cout << "\nNode " << node->data << " sudah ada child kiri." << endl;
        return NULL;
    }

    baru = new Pohon{data, NULL, NULL, node};
    node->left = baru;
    cout << "\nNode " << data << " berhasil ditambahkan ke child kiri " << node->data << endl;
    return baru;
}

Pohon *insertRight(int data, Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree dulu!" << endl;
        return NULL;
    }

    if (node->right != NULL) {
        cout << "\nNode " << node->data << " sudah ada child kanan." << endl;
        return NULL;
    }

    baru = new Pohon{data, NULL, NULL, node};
    node->right = baru;
    cout << "\nNode " << data << " berhasil ditambahkan ke child kanan " << node->data << endl;
    return baru;
}

bool is_valid_bst(Pohon *node, int min_val, int max_val) {
    if (!node)
        return true;

    if (node->data <= min_val || node->data >= max_val)
        return false;

    return is_valid_bst(node->left, min_val, node->data) && is_valid_bst(node->right, node->data, max_val);
}

//Valid
// int main() {
//     init();
//     buatNode(10);
//     Pohon *node5 = insertLeft(5, root);  
//     Pohon *node15 = insertRight(15, root);
//     insertLeft(3, node5);  
//     insertRight(7, node5); 
//     insertLeft(13, node15);  
//     insertRight(17, node15);

//     
//     cout << "Memeriksa apakah tree adalah BST: " << endl;
//     if (is_valid_bst(root, INT_MIN, INT_MAX))
//         cout << "Tree adalah Binary Search Tree yang valid." << endl;
//     else
//         cout << "Tree bukan Binary Search Tree yang valid." << endl;

//     return 0;
// }

//Tidak valid
int main() {
    init();
    buatNode(10); 
    Pohon *node5 = insertLeft(15, root);
    Pohon *node15 = insertRight(5, root); 
    insertLeft(3, node5); 
    insertRight(7, node5); 
    insertLeft(13, node15);  
    insertRight(17, node15); 

    cout << "Memeriksa apakah tree adalah BST: " << endl;
    if (is_valid_bst(root, INT_MIN, INT_MAX)) 
        cout << "Tree adalah Binary Search Tree yang valid." << endl;
    else
        cout << "Tree bukan Binary Search Tree yang valid." << endl;

    return 0;
}
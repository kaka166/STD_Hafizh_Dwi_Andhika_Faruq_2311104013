#include <iostream>
using namespace std;

struct Pohon
{
    char data;
    Pohon *left, *right, *parent;
};

Pohon *root, *baru;

void init()
{
    root = NULL;
}

bool isEmpty()
{
    return root == NULL;
}

void buatNode(char data)
{
    if (isEmpty())
    {
        root = new Pohon{data, NULL, NULL, NULL};
        cout << "\nNode " << data << " berhasil dibuat jadi root" << endl;
    }
    else
    {
        cout << "\nPohon sudah dibuat." << endl;
    }
}

Pohon *insertLeft(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree dulu." << endl;
        return NULL;
    }

    if (node->left != NULL)
    {
        cout << "\nNode " << node->data << " sudah ada child kiri." << endl;
        return NULL;
    }

    baru = new Pohon{data, NULL, NULL, node};
    node->left = baru;
    cout << "\nNode " << data << " berhasil ditambahkan ke child kiri " << node->data << endl;
    return baru;
}

Pohon *insertRight(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree dulu!" << endl;
        return NULL;
    }

    if (node->right != NULL)
    {
        cout << "\nNode " << node->data << " sudah ada child kanan." << endl;
        return NULL;
    }

    baru = new Pohon{data, NULL, NULL, node};
    node->right = baru;
    cout << "\nNode " << data << " berhasil ditambahkan ke child kanan " << node->data << endl;
    return baru;
}

int cari_simpul_daun(Pohon *node)
{
    if (node == NULL)
        return 0; 

    if (node->left == NULL && node->right == NULL)
        return 1;

    return cari_simpul_daun(node->left) + cari_simpul_daun(node->right);
}

int main()
{
    init();

    buatNode('A'); 
    Pohon *nodeB = insertLeft('B', root); 
    Pohon *nodeC = insertRight('C', root);
    insertLeft('D', nodeB); 
    insertRight('E', nodeB);
    insertRight('F', nodeC);

    // Menghitung jumlah simpul daun
    int jumlahDaun = cari_simpul_daun(root);
    cout << "Jumlah simpul daun dalam pohon: " << jumlahDaun << endl;

    return 0;
}

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

void tampilkanAnak(Pohon *node)
{
    if (!node)
    {
        cout << "\nNode tidak ditemukan." << endl;
        return;
    }

    cout << "\nChild dari node " << node->data << ": ";
    if (node->left)
        cout << "Left child: " << node->left->data << ", ";
    else
        cout << "Tidak ada child kiri, ";

    if (node->right)
        cout << "Right child: " << node->right->data << endl;
    else
        cout << "Tidak ada child kanan" << endl;
}

void tampilkanDescendant(Pohon *node)
{
    if (!node)
        return;
    if (node->left)
    {
        cout << node->left->data << " ";
        tampilkanDescendant(node->left);
    }
    if (node->right)
    {
        cout << node->right->data << " ";
        tampilkanDescendant(node->right);
    }
}

int main()
{
    init();
    char pilihan, data;
    Pohon *tempNode = nullptr;

    do
    {
        cout << "\n--- Menu ---" << endl;
        cout << "1. Buat Node Root" << endl;
        cout << "2. Tambah Node Kiri" << endl;
        cout << "3. Tambah Node Kanan" << endl;
        cout << "4. Tampilkan Anak Node" << endl;
        cout << "5. Tampilkan Descendant Node" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan)
        {
        case '1':
            cout << "Masukkan data root: ";
            cin >> data;
            buatNode(data);
            break;

        case '2':
            if (!isEmpty())
            {
                cout << "Masukkan data node kiri: ";
                cin >> data;
                cout << "Masukkan data parent: ";
                char parentData;
                cin >> parentData;

                Pohon *parent = (root->data == parentData) ? root : NULL;
                if (parent)
                {
                    insertLeft(data, parent);
                }
                else
                {
                    cout << "\nParent tidak ditemukan." << endl;
                }
            }
            else
            {
                cout << "\nBuat tree dulu." << endl;
            }
            break;

        case '3':
            if (!isEmpty())
            {
                cout << "Masukkan data node kanan: ";
                cin >> data;
                cout << "Masukkan data parent: ";
                char parentData;
                cin >> parentData;

                Pohon *parent = (root->data == parentData) ? root : NULL;
                if (parent)
                {
                    insertRight(data, parent);
                }
                else
                {
                    cout << "\nParent tidak ditemukan." << endl;
                }
            }
            else
            {
                cout << "\nBuat tree dulu!" << endl;
            }
            break;

        case '4':
            if (!isEmpty())
            {
                cout << "Masukkan data node untuk melihat anak: ";
                char nodeData;
                cin >> nodeData;

                Pohon *node = (root->data == nodeData) ? root : NULL;
                if (node)
                {
                    tampilkanAnak(node);
                }
                else
                {
                    cout << "\nNode tidak ditemukan." << endl;
                }
            }
            else
            {
                cout << "\nBuat tree dulu!" << endl;
            }
            break;

        case '5':
            if (!isEmpty())
            {
                cout << "Masukkan data node untuk melihat descendant: ";
                char nodeData;
                cin >> nodeData;

                Pohon *node = (root->data == nodeData) ? root : NULL;
                if (node)
                {
                    cout << "\nDescendant dari node " << nodeData << ": ";
                    tampilkanDescendant(node);
                    cout << endl;
                }
                else
                {
                    cout << "\nNode tidak ditemukan." << endl;
                }
            }
            else
            {
                cout << "\nBuat tree dulu!" << endl;
            }
            break;

        case '0':
            cout << "\nKeluar program." << endl;
            break;

        default:
            cout << "\nPilihan tidak valid." << endl;
        }
    } while (pilihan != '0');

    return 0;
}

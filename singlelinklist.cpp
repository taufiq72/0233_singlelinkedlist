#include <iostream>
#include <string>
using namespace std;

class Node
{
public:                     
    int noMhs;
    Node*next;
};

class LinkedList
{
    Node*START;

    public:
    LinkedList()
    {
        START = NULL;
    }

    void addNode()
    {
        int nim;
        cout << "\nMasukkan NIM Mahasiswa: ";
        cin >> nim;

        Node *Nodebaru = new Node();
        Nodebaru->noMhs = nim;

        if (START == NULL || START->noMhs >= Nodebaru->noMhs)
        {
            if (START != NULL && nim == START->noMhs)
            {
                cout << "\nDuplikasi noMhs tidak di ijinkan\n";
                return;
            }

            Nodebaru->next = START;
            START = Nodebaru;
            return;
        }

        Node *previous = START;
        Node *current = START;

        while (current != NULL && nim > current->noMhs)
        {
            if (nim == current->noMhs)
            {
                cout << "\nDuplikasi noMhs tidak di ijinkan\n";
                return;
            }
            previous = current;
            current = current->next;
        }

        Nodebaru->next = current;
        previous->next = Nodebaru;
    }

    bool listEmpty()
    {
        return START == NULL;
    }

    bool search(int nim, Node **previous, Node **current)
    {
        *previous = START;
        *current = START;

        while (*current != NULL && nim != (*current)->noMhs)
        {
            *previous = *current;
            *current = (*current)->next;
        }
        return (*current != NULL);
    }

    bool delNode(int nim)
    {
        Node *previous, *current;
        if (!search(nim, &previous, &current))
            return false;

        if (current == START)
        {
            START = START->next;
        }
        else
        {
            previous->next = current->next;
        }
        delete current;
        return true;
    }

    void traverse()
    {
        if (listEmpty())
        {
            cout << "\nList Kosong\n";
            return;
        }
        cout << "\nData di dalam list adalah: \n";
        Node *current = START;

        while (current != NULL)
        {
            cout << current->noMhs << endl;
            current = current->next;
        }
        cout << endl;
    }
};

int main()
{
    LinkedList mhs;
    int nim;
    char ch;

    do
    {
        cout << "\nMenu: \n";
        cout << "1. Menambah data ke dalam list\n";
        cout << "2. Menghapus Data dari dalam list\n";
        cout << "3. Menampilkan semua data di dalam list\n";
        cout << "4. Mencari data dalam list" << endl;
        cout << "5. Keluar\n";

        cout << "Masukkan pilihan (1-5): ";
        cin >> ch;

        switch (ch)
        {
        case '1':
            mhs.addNode();
            break;
        case '2':
            if (mhs.listEmpty())
            {
                cout << "\nList Kosong" << endl;
                break;
            }

            cout << "\nMasukkan NIM yang akan dihapus: ";
            cin >> nim;

            if (mhs.delNode(nim) == false)
            {
                cout << "\ndata tidak ditemukan" << endl;
            }
            else
            {
                cout << "\ndata dengan Nomor mahasiswa " << nim << " berhasil dihapus\n";
            }
            break;
        case '3':
            mhs.traverse();
            break;

        }
    }
}
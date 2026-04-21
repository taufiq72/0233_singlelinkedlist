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

};
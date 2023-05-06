// ap12.4.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <iomanip>
using namespace std;

typedef int Info;
struct Elem
{
    Elem* link;
    Info info;
};

void Insert(Elem*& L, Info value)
{
    Elem* tmp = new Elem;
    tmp->info = value;
    if (L != NULL)
    {
        Elem* T = L;
        while (T->link != L)
            T = T->link;
        T->link = tmp;
    }
    else
    {
        L = tmp;
    }
    tmp->link = L;
}

void Remove(Elem*& first, Info value)
{
    if (first == NULL)
        return;

    Elem* current = first;
    Elem* previous = NULL;

    do
    {
        if (current->info == value)
        {
            if (previous != NULL)
            {
                previous->link = current->link;
                delete current;
                current = previous->link;
            }
            else
            {
                Elem* last = first;
                while (last->link != first)
                    last = last->link;
                first = first->link;
                last->link = first;
                delete current;
                current = first;
            }
        }
        else
        {
            previous = current;
            current = current->link;
        }
    } while (current != first);

    Elem* tmp = first;
    while (tmp != NULL && tmp->info == value)
    {
        first = tmp->link;
        delete tmp;
        tmp = first;
    }

    current = first;
    while (current != NULL && current->link != first)
    {
        if (current->link->info == value)
        {
            tmp = current->link;
            current->link = tmp->link;
            delete tmp;
        }
        else
        {
            current = current->link;
        }
    }
}

void Print(Elem* L) {
    if (L == NULL)
        return;
    Elem* first = L;
    cout << setw(4) << L->info;
    while (L->link != first)
    {
        L = L->link;
        cout << setw(4) << L->info;
    }
    cout << endl;
}

int main()
{
    Elem* L = NULL;
    Insert(L, 5);
    Insert(L, 2);
    Insert(L, 5);
    Insert(L, 5);
    Insert(L, 7);
    Insert(L, 7);
    Print(L);

    int value;
    cout << "Enter a value to remove: ";
    cin >> value;

    Remove(L, value);
    Print(L);

    return 0;
}

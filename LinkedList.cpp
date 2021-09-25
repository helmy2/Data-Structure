#include <iostream>
using namespace std;

class LinkedList
{
private:
    struct Node
    {
        int value;
        Node *next;
    };

    Node *first;
    Node *last;

public:
    LinkedList();

    void insertFirst(int value);
    void insertLast(int value);
    int removeFirst();
    int removeLast();

    void sort();
    bool isEmpty();
    void display();
};

int main()
{
    LinkedList list;
    list.insertFirst(4);
    list.insertFirst(5);
    list.insertFirst(6);

    cout << "add to first (4, 5, 6)" << endl;
    list.display();
    cout << endl;

    cout << "sort" << endl;
    list.sort();
    list.display();
    cout << endl;

    list.insertLast(7);
    list.insertLast(8);
    list.insertLast(9);

    cout << "add to last (7, 8, 9)" << endl;
    list.display();
    cout << endl;

    cout << "sort" << endl;
    list.sort();
    list.display();
    cout << endl;

    list.removeFirst();

    cout << "remove first" << endl;
    list.display();
    cout << endl;

    list.removeLast();

    cout << "remove last" << endl;
    list.display();
    cout << endl;

    cin.get();
}

LinkedList::LinkedList()
{
    first = last = nullptr;
}

void LinkedList::insertFirst(int value)
{
    Node *temp = new Node;
    temp->value = value;
    temp->next = first;

    if (isEmpty())
    {
        first = temp;
        last = first;
    }
    else
        first = temp;
}

void LinkedList::insertLast(int value)
{
    Node *temp = new Node;
    temp->value = value;
    temp->next = nullptr;

    if (isEmpty())
    {
        first = last = temp;
        return;
    }

    last->next = temp;
    last = temp;
}

int LinkedList::removeFirst()
{
    if (isEmpty())
        return -1;

    int value = first->value;

    Node *temp = first;
    first = first->next;

    free(temp);
    return value;
}

int LinkedList::removeLast()
{
    if (isEmpty())
        return -1;

    int value = last->value;

    Node *temp = first;
    while (temp->next != last)
    {
        temp = temp->next;
    }
    last = temp;
    last->next = nullptr;

    free(temp->next);
    return value;
}

void LinkedList::sort()
{
    if (isEmpty())
        return;

    Node *cur = first;
    Node *temp = cur->next;
    while (cur != nullptr)
    {
        while (temp != nullptr)
        {
            if (cur->value > temp->value)
                swap(cur->value, temp->value);
            temp = temp->next;
        }
        cur = cur->next;
    }
}

bool LinkedList::isEmpty()
{
    if (first == nullptr)
        return true;
    return false;
}

void LinkedList::display()
{
    if (isEmpty())
        return;

    Node *temp = first;
    while (temp != nullptr)
    {
        cout << temp->value << "\t";
        temp = temp->next;
    }
    cout << endl;
}
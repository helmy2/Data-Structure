#include <iostream>
using namespace std;

class Queue
{
private:
    struct Node
    {
        int value;
        Node *next;
    };
    Node *front;
    Node *rear;

public:
    Queue();
    void enqueue(int value);
    int dequeue();
    void display();
    bool isEmpty();
};

Queue::Queue()
{
    front = rear = nullptr;
}

void Queue::enqueue(int value)
{
    Node *temp = new Node;
    temp->value = value;
    temp->next = nullptr;

    if (isEmpty())
    {
        front = rear = temp;
        return;
    }

    rear->next = temp;
    rear = temp;
}

int Queue::dequeue()
{
    if (isEmpty())
    {
        cout << "Underflow" << endl;
        exit(0);
    }
    Node *temp = front;
    front = front->next;
    int value = temp->value;
    free(temp);
    return value;
}

void Queue::display()
{
    Node *temp = front;
    if (isEmpty())
    {
        cout << "Queue is empty" << endl;
        return;
    }
    cout << "Queue elements are: ";
    while (temp != nullptr)
    {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
}

bool Queue::isEmpty()
{
    return front == nullptr;
}

int main()
{
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    q.display();

    cout << "dequeue:" << q.dequeue() << endl;

    q.display();
}

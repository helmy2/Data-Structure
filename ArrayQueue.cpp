#include <iostream>
using namespace std;
#define maxSize 100

class Queue
{
private:
    int queueArray[maxSize];
    int front, rear;

public:
    Queue();
    void enqueue(int value);
    int dequeue();
    void display();
    bool isEmpty();
    bool isFull();
};

Queue::Queue()
{
    front = rear = -1;
}

void Queue::enqueue(int value)
{
    if (isFull())
    {
        cout << "queue is overflow";
        return;
    }
    if (front == -1)
        front = 0;
    rear++;
    queueArray[rear] = value;
}

int Queue::dequeue()
{
    if (isEmpty())
    {
        cout << "queue is underflow";
        exit(0);
    }
    if (front == rear)
    {
        int value = queueArray[front];
        front = rear = -1;
        return value;
    }
    int value = queueArray[front];
    front++;
    return value;
}

void Queue::display()
{
    if (isEmpty())
    {
        cout << "Queue is empty" << endl;
        return;
    }
    cout << "Queue elements are: ";
    for (int i = front; i <= rear; i++)
    {
        cout << queueArray[i] << " ";
    }
    cout << endl;
}

bool Queue::isEmpty()
{
    return front == -1;
}

bool Queue::isFull()
{
    return rear == maxSize;
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

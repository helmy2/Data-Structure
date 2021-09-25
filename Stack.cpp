#include <iostream>
using namespace std;

class Stack
{
private:
    struct Node
    {
        int value;
        Node *next;
    };
    Node *top;

public:
    Stack();
    bool isEmpty();
    bool isFull();
    void push(int value);
    int pop();
    int peek();
    void display();
};

Stack::Stack()
{
    top = nullptr;
}

bool Stack::isEmpty()
{
    return top == nullptr;
}

void Stack::push(int value)
{
    Node *temp = new Node;
    temp->value = value;

    temp->next = top;
    top = temp;
}

int Stack::pop()
{
    if (isEmpty())
    {
        cout << "Stack is underflow";
        return -1;
    }

    Node *temp = top;
    int value = temp->value;
    top = top->next;
    free(temp);
    return value;
}

int Stack::peek()
{
    if (isEmpty())
    {
        cout << "Stack is underflow";
        return -1;
    }
    return top->value;
}

void Stack::display()
{
    if (isEmpty())
    {
        cout << "the stack is empty " << endl;
        return;
    }
    Node *temp = top;
    while (temp != nullptr)
    {
        cout << temp->value << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(6);
    s.push(0);

    s.display();
    cout << "pop: " << s.pop() << endl;
    s.display();
    cout << "pop: " << s.pop() << endl;
    s.display();
    cout << "peek: " << s.peek() << endl;
    s.display();
    cout << "pop: " << s.pop() << endl;
    s.display();
    cout << "pop: " << s.pop() << endl;
    s.display();
}

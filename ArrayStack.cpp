#include <iostream>
using namespace std;
#define maxSize 100

class Stack
{
private:
    int stackArray[maxSize];
    int top;

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
    top = -1;
}

bool Stack::isEmpty()
{
    return top == -1;
}

bool Stack::isFull()
{
    return top == maxSize - 1;
}

void Stack::push(int value)
{
    if (isFull())
    {
        cout << "Stack is overflow";
        return;
    }
    top++;
    stackArray[top] = value;
}

int Stack::pop()
{
    if (isEmpty())
    {
        cout << "Stack is underflow";
        return -1;
    }
    int value = stackArray[top];
    top--;
    return value;
}

int Stack::peek()
{
    if (isEmpty())
    {
        cout << "Stack is underflow";
        return -1;
    }
    return stackArray[top];
}

void Stack::display()
{
    if (isEmpty())
    {
        cout << " the stack is empty " << endl;
        return;
    }
    for (int i = top; i >= 0; i--)
        cout << stackArray[i] << " ";
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
}

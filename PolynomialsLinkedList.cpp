#include <iostream>
using namespace std;

class Polynomials
{
private:
    struct Node
    {
        int coeff;
        int power;
        struct Node *next;
    };
    Node *head = NULL;

public:
    void insert(int coeff, int power)
    {
        Node *temp = new Node;
        temp->coeff = coeff;
        temp->power = power;
        temp->next = NULL;

        if (head == NULL)
        {
            head = temp;
            return;
        }

        Node *cur = head;
        while (cur != NULL)
        {
            if (cur->power == temp->power)
            {
                cur->coeff += temp->coeff;
                return;
            }
            cur = cur->next;
        }
        temp->next = head;
        head = temp;
    }
    void display()
    {
        if (head == NULL)
        {
            cout << "list is empty ";
            return;
        }

        Node *temp = head;
        cout << "the elements of the list are   " << endl;
        while (temp != NULL)
        {
            cout << temp->coeff << "(x^" << temp->power << ")";
            if (temp->next != NULL)
                cout << " + ";
        
            temp = temp->next;
        }
        cout << endl;
    }

    Polynomials operator+(Polynomials polynomials)
    {
        Polynomials result = polynomials;

        Node *temp = head;
        while (temp != NULL)
        {
            result.insert(temp->coeff, temp->power);
            temp = temp->next;
        }
        return result;
    }

};

int main()
{
    Polynomials x;
    x.insert(3, 2);
    x.insert(1, 3);
    x.insert(1, 2);
    x.insert(1, 2);
    x.insert(1, 2);

    x.display();

    Polynomials y;
    y.insert(1, 2);
    y.insert(5, 4);

    y.display();

    Polynomials z = x + y;
    z.display();
}

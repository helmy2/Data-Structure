#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

class BST
{
private:
    Node *root;

    void preOrder(Node *root)
    {
        if (root == NULL)
            return;
        cout << root->data << "\t";
        preOrder(root->left);
        preOrder(root->right);
    }

    void inOrder(Node *root)
    {
        if (root == NULL)
            return;
        inOrder(root->left);
        cout << root->data << "\t";
        inOrder(root->right);
    }

    void postOrder(Node *root)
    {
        if (root == NULL)
            return;
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << "\t";
    }

    Node *search(Node *root, int d)
    {
        if (root == NULL || root->data == d)
            return root;

        if (d < root->data)
            return search(root->left, d);

        return search(root->right, d);
    }

    Node *insert(Node *root, int value)
    {
        if (root == NULL)
        {
            root = new Node;
            root->data = value;
            root->left = root->right = nullptr;
        }
        else if (value < root->data)
        {
            root->left = insert(root->left, value);
        }
        else
        {
            root->right = insert(root->right, value);
        }
        return root;
    }

    Node *remove(Node *root, int data)
    {
        if (root == NULL)
            return root;

        if (data < root->data)
            root->left = remove(root->left, data);

        else if (data > root->data)
            root->right = remove(root->right, data);

        else
        {

            if (root->left == NULL)
            {
                Node *temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == NULL)
            {
                Node *temp = root->left;
                delete root;
                return temp;
            }

            Node *temp = root->right;

            // Find the leftmost leaf
            while (temp && temp->left != NULL)
                temp = temp->left;

            root->data = temp->data;

            root->right = remove(root->right, temp->data);
        }
        return root;
    }

public:
    BST(){
        root = nullptr;
    }

    void insert(int x)
    {
        root  = insert(root, x);
    }

    void remove(int x)
    {
        root = remove(root, x);
    }

    void display()
    {
        cout << "pre order\t";
        preOrder(root);
        cout << endl;

        cout << "in order\t";
        inOrder(root);
        cout << endl;

        cout << "post order\t";
        postOrder(root);
        cout << endl;
    }

    void search(int x)
    {
        search(root, x);
    }
};

int main()
{
    BST b;

    b.insert(50);
    b.insert(25);
    b.insert(75);
    b.insert(10);
    b.insert(30);
    b.insert(100);
    b.insert(60);

    //          50
    //     25          75
    // 10     30    60    100

    //pre order
    //50 25 10 30 75 60 100

    //in order
    //10 25 30 50 60 75 100

    //pre order
    //10 30 25 60 100 75 50

    b.display();

    b.remove(50);
    cout << "delete 50 \n";

    b.display();
}
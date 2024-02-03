#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

class Node 
{
public:
    Node *left;
    int data;
    Node *right;
    Node *parent;

    Node(int val) : left(NULL), data(val), right(NULL), parent(NULL) {}
};

class MaxBinaryHeap
{
    Node *root;

public:
    MaxBinaryHeap() : root(NULL) {}

    void insert(int value)
    {
        Node *newNode = new Node(value);

        if (root == NULL)
        {
            root = newNode;
            return;
        }

        queue<Node*> Q;
        Q.push(root);

        while (!Q.empty())
        {
            Node *temp = Q.front();
            if (temp->left == NULL)
            {
                temp->left = newNode;
                newNode->parent = temp;
                break;
            }
            else if (temp->right == NULL)
            {
                temp->right = newNode;
                newNode->parent = temp;
                break;
            }
            Q.pop();
            Q.push(temp->left);
            Q.push(temp->right);
        }

        heapifyUp(newNode);
    }

    void heapifyUp(Node *node)
    {
        while (node->parent != NULL && node->parent->data < node->data)
        {
            swap(node->data, node->parent->data);
            node = node->parent;
        }
    }

    void display()
    {
        if (root == NULL)
        {
            cout << "Max Binary Heap is empty." << endl;
            return;
        }

        queue<Node*> Q;
        Q.push(root);

        while (!Q.empty())
        {
            Node *temp = Q.front();
            cout << temp->data << " ";

            if (temp->left != NULL)
                Q.push(temp->left);
            if (temp->right != NULL)
                Q.push(temp->right);

            Q.pop();
        }

        cout << endl;
    }
};

int main()
{
    MaxBinaryHeap maxHeap;
    maxHeap.insert(5);
    maxHeap.insert(10);
    maxHeap.insert(7);
    maxHeap.insert(3);
    maxHeap.insert(1);

    cout << "Max Binary Heap elements: ";
    maxHeap.display();

    return 0;
}

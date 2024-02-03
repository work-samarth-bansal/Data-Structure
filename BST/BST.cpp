#include <iostream>
using namespace std;

class Node
{
public:
    Node* left;
    int data;
    Node* right;

    Node(int val): left(NULL), data(val), right(NULL) {}
};

class BinarySearchTree
{
    public:

    Node *root;

    BinarySearchTree()
    {
        root = NULL;
    }

    Node* Insert(Node *p, int key)
    {
        if(p == NULL)
            return new Node(key);

        if(key > p->data)
            p->right = Insert(p->right, key);

        else if(key < p->data)
            p->left = Insert(p->left, key);

        return p;
    }


    bool Search(Node *p, int key)
    {
        if(p == NULL)
            return false;
        
        if(key == p->data)
            return true;

        else if(key > p->data)
            return Search(p->right, key);

        else if(key < p->data)
            return Search(p->left, key);
    }

    Node* Successor(Node *p)
    {
        Node* current = p;

        while (current && current->left != NULL)
            current = current->left;

        return current;
    }



    Node* Delete(Node *p, int key)
    {
        if(p == NULL)
        {
            cout << "Element Not Found" << endl;
            return NULL;
        }
        
        if(key > p->data)
            p->right = Delete(p->right, key);

        else if(key < p->data)
            p->left = Delete(p->left, key);

        else
        {
            if(p->left == NULL)
            {
                Node *temp = p->right;
                delete p;
                return temp;
            }

            else if(p->right == NULL)
            {
                Node *temp = p->left;
                delete p;
                return temp;
            }

            Node *temp = Successor(p->right);
            p->data = temp->data;
            p->right = Delete(p->right, temp->data); 
        }

        return p;
    }


    void PreOrder(Node *p)
    {
        if(p)
        {
            cout<<p->data<<" ";
            PreOrder(p->left);
            PreOrder(p->right);
        }
    }

    void InOrder(Node *p)
    {
        if(p)
        {
            InOrder(p->left);
            cout<<p->data<<" ";
            InOrder(p->right);
        }
    }

    void PostOrder(Node *p)
    {
        if(p)
        {
            PostOrder(p->left);
            PostOrder(p->right);
            cout<<p->data<<" ";
        }
    }
};

int main() {
    BinarySearchTree BST;
    int choice, element;
    do {
        cout << "Options: 1.Insert 2.Delete 3.Inorder 4.Postorder 5.Search 6.Exit" << endl;
        cout << "Enter choice:";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Element to be inserted:";
                cin >> element;
                BST.root = BST.Insert(BST.root, element);
                break;

            case 2:
                cout << "Element to be deleted:";
                cin >> element;
                BST.root = BST.Delete(BST.root, element);
                break;

            case 3:
                cout << "BST Inorder Traversal is:";
                BST.InOrder(BST.root);
                cout << endl;
                break;

            case 4:
                cout << "BST Postorder Traversal is:";
                BST.PostOrder(BST.root);
                cout << endl;
                break;

            case 5:
                cout << "Element to be searched:";
                cin >> element;
                if (BST.Search(BST.root, element)) {
                    cout << "Element " << element << " Found" << endl;
                } else {
                    cout << "Element not found" << endl;
                }
                break;

            case 6:
                cout << "Program Exit" << endl;
                return 0;

            default:
                cout << "Enter correct choice:" << endl;
        }
    } while (1);
}

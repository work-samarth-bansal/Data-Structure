#include <iostream>
#include <queue>
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

    void Levelorder(Node *p)
    {
        queue<Node*> Q;

        Node *tab;
        int hgt = Height(root);
        Q.push(root);
        Q.push(NULL);

        for(int i = 0 ; i<hgt ; i++)
        {
            cout<<"\t";
        }
        hgt--;

        while(!Q.empty())
        {
            if(Q.front() == NULL)
            {
                cout<<endl;

                for(int i = 0 ; i<hgt ; i++)
                {
                    cout<<"\t";
                }
                hgt--;

                Q.pop();

                if(!Q.empty())
                {
                    Q.push(NULL);
                }
            }

            else if(Q.front() == tab)
            {
                Q.pop();
                cout<<"\t";
            }

            else
            {
                Node *temp = Q.front();
                Q.pop();

                cout<<temp->data<<"\t\t";

                if(temp->left)
                    Q.push(temp->left);
                else
                    Q.push(tab);

                if(temp->right)
                    Q.push(temp->right);
                else
                    Q.push(tab);
            }
        }
    }

    int Height(Node* p)
    {
        if(!p)
            return 0;
        
        int x = Height(p->left);
        int y = Height(p->right);

        if(x>y)
            return x+1;
        else
            return y+1;

    }

    int Width(Node* p)
    {
        static int ans = 0;

        if(!p)
            return 0;
        
        int x = Height(p->left);
        int y = Height(p->right);

        ans = max(x+y+1, ans); 
        return ans;

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
    
    int arr[] = {6,4,7,9,2,8,1,5,3};
    int len = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < len; i++)
    {
        BST.root = BST.Insert(BST.root,arr[i]);
    }

    BST.Levelorder(BST.root);

    cout<<"Height of Tree's Root is "<<BST.Height(BST.root)<<endl;

    cout<<"Diameter of Tree is "<<BST.Width(BST.root)<<endl;
}

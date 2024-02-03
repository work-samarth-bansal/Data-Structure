#include <iostream>
#include <queue>
using namespace std;

class Node
{
    public:
    Node *left;
    int data;
    Node *right;

    Node(int num): left(NULL), data(num), right(NULL){}
};

class BinaryTree
{
    public:
    Node *root;

    BinaryTree()
    {
        root = NULL;
    }

    void Create();
    void Preorder(Node *p);
    void LevelOrder(Node *p);

};

void BinaryTree::Create()
{
    queue<Node*> Q;
    int n;
    cout << "Enter the value for Root Node: ";
    cin >> n;
    root = new Node(n);
    Q.push(root);

    while (!Q.empty())
    {
        Node* p = Q.front();
        char yn;
        int val;
        
        cout << "Is there a Left child of "<< p->data <<" Node (y/n): ";
        cin >> yn;
        if (yn == 'y')
        {
            cout << "Enter Value: ";
            cin >> val;
            p->left = new Node(val);
            Q.push(p->left);
        }

        cout << "Is there a Right child of "<< p->data <<" Node (y/n): ";
        cin >> yn;
        if (yn == 'y')
        {
            cout << "Enter Value: ";
            cin >> val;
            p->right = new Node(val);
            Q.push(p->right);
        }
        Q.pop();
    }
}

void BinaryTree::Preorder(Node *p)
{
    if(p)
    {
        cout<<p->data<<" , ";
        Preorder(p->left);
        Preorder(p->right);
    }
}

void BinaryTree::LevelOrder(Node *root)
{
    queue <Node*> Q;
    Q.push(root);
    
    while(!Q.empty())
    {
        Node *p = Q.front();
        Q.pop();
        cout<< p->data <<" , ";
        if(p->left)
            Q.push(p->left);
        if(p->right)
            Q.push(p->right);
    }
    cout<<endl;

}


int main()
{
    BinaryTree T;
    T.Create();
    T.LevelOrder(T.root);
}
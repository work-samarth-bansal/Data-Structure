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
    int Height(Node *p);
    int Balancefactor(Node *p);
    void PrintLeaf(Node *p);
    int Width(Node* p);

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

int BinaryTree::Height(Node* p)
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

int BinaryTree::Width(Node* p)
{
    static int ans = 0;

    if(!p)
        return 0;
    
    int x = Height(p->left);
    int y = Height(p->right);

    ans = max(x+y+1, ans); 
    return ans;

}

int BinaryTree::Balancefactor(Node* p)
{
    return Height(p->left) - Height(p->right);
}

void BinaryTree::LevelOrder(Node *root)
{
    queue <Node*> Q;
    Q.push(root);
    Q.push(NULL);

    while(!Q.empty())
    {
        Node* p = Q.front();
        Q.pop();

        if(p == NULL)
        {
            cout<<endl;

            if(!Q.empty())
            {
                Q.push(NULL);
            }
        }
        else
        {
            cout<< p->data <<" ";

            if(p->left)
                Q.push(p->left);
            
            if(p->right)
                Q.push(p->right);
        }
    }
    cout<<endl;
}


void BinaryTree::PrintLeaf(Node *p)
{
    if(p->left == NULL && p->right == NULL)
        cout<<p->data<<" ";
    else
    {
        PrintLeaf(p->left);
        PrintLeaf(p->right);
    }
}


int main()
{
    BinaryTree T;
    T.Create();
    T.LevelOrder(T.root);
    cout<<"Height of Tree is "<<T.Height(T.root)<<endl;
    cout<<"Balance Factor of Tree's Root is "<<T.Balancefactor(T.root)<<endl;

    cout<<"Diameter of Tree is "<<T.Width(T.root)<<endl;

    T.PrintLeaf(T.root);
    cout<<endl;
}
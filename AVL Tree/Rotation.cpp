#include <iostream>
using namespace std;

class Node
{
    public:
    Node *left;
    int data;
    int height;
    Node *right;

    Node(int num=0, int hgt=0): left(NULL), data(num), height(hgt), right(NULL){}
};

class AVL_Tree
{
    public :

    Node *root;

    AVL_Tree() : root(NULL) {}

    int NodeHeight(Node *p)
    {
        int hl,hr;
        hl=p && p->left?p->left->height:0;
        hr=p && p->right?p->right->height:0;

        return hl>hr?hl+1:hr+1;
    }

    int BalanceFactor(Node *p)
    {
        int hl,hr;
        hl=p && p->left?p->left->height:0;
        hr=p && p->right?p->right->height:0;

        return hl-hr;                       //return (p ? NodeHeight(p->left) - NodeHeight(p->right) : 0);
    }

    Node * LLRotation(Node *p)
    {
        Node *pl = p->left;
        Node *plr = pl->right;

        p->left = plr;
        pl->right = p;

        p->height=NodeHeight(p);
        pl->height=NodeHeight(pl);

        if(root==p)
            root=pl;
    
        return pl;
    }

    Node * LRRotation(Node *p)
    {
        Node *pl = p->left;
        Node *plr = pl->right;
        Node *plrl = plr->left;
        Node *plrr = plr->right;

        plr->left = pl;
        plr->right = p;
        p->left = plrr;
        pl->right = plrl;

        pl->height=NodeHeight(pl);
        p->height=NodeHeight(p);
        plr->height=NodeHeight(plr);

        if(root==p)
            root=plr;

        return plr;
    }

    Node * RRRotation(Node *p)
    {
        Node *pr = p->right;
        Node *prl = pr->left;

        p->left = prl;
        pr->left = p;

        p->height =  NodeHeight(p);
        pr->height = NodeHeight(pr);

        if(root==p)
            root=pr;

        return pr;
    }

    Node * RLRotation(Node *p)
    {
        Node *pr = p->right;
        Node *prl = pr->left;

        p->right = prl->left;
        pr->left = prl->right;

        prl->left = p;
        prl->right = pr;

        p->height =  NodeHeight(p);
        pr->height = NodeHeight(pr);
        prl->height = NodeHeight(prl);

        if(root==p)
            root=prl;

        return prl;
    }

    Node * RInsert(Node *p,int key)
    {
        Node *t=NULL;

        if(p==NULL)
        {
            t=new Node;
            t->data=key;
            t->height=1;
            t->left = t->right = NULL;
            return t;
        }
        if(key < p->data)
            p->left=RInsert(p->left,key);
        else if(key > p->data)
            p->right=RInsert(p->right,key);

        p->height=NodeHeight(p);

        // if(BalanceFactor(p)==2 && BalanceFactor(p->left)==1)
        //     return LLRotation(p);
        // else if(BalanceFactor(p)==2 && BalanceFactor(p->left)==-1)
        //     return LRRotation(p);
        // else if(BalanceFactor(p)==-2 && BalanceFactor(p->right)==-1)
        //     return RRRotation(p);
        // else if(BalanceFactor(p)==-2 && BalanceFactor(p->right)==1)
        //     return RLRotation(p);

        int balance = BalanceFactor(p);
        if (balance > 1) {
            if (key < p->left->data)
                return LLRotation(p);
            else
                return LRRotation(p);
        }
        if (balance < -1) {
            if (key > p->right->data)
                return RRRotation(p);
            else
                return RLRotation(p);
        }

        return p;

    }

    void Insert(int key) {
        root = RInsert(root, key);
    }

    void destroyTree(Node* node)
    {
        if (node) {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }

    ~AVL_Tree()
    {
        destroyTree(root);
    }

    void Inorder(Node *p)
    {
        if(p)
        {
            Inorder(p->left);
            cout<<p->data<<" , ";
            Inorder(p->right);
        }
    }
};


int main()
{
    AVL_Tree avlTree;

    avlTree.Insert(10);
    avlTree.Insert(20);
    avlTree.Insert(5);
    avlTree.Insert(15);
    avlTree.Insert(30);

    cout << "Inorder Traversal of AVL Tree: ";
    avlTree.Inorder(avlTree.root);
    cout << endl;

    return 0;
}


// Corrected LR Rotation
// Node* LRRotation(Node* p) {
//     p->left = RRRotation(p->left);
//     return LLRotation(p);
// }

// Corrected RL Rotation
// Node* RLRotation(Node* p) {
//     p->right = LLRotation(p->right);
//     return RRRotation(p);
// }
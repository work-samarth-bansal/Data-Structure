#include <iostream>
#include <stack>
using namespace std;

class Node
{
    public:
    Node *left;
    int data;
    Node *right;

    Node(int num): left(NULL), data(num), right(NULL){}
};

class BST
{
    public:
    Node *root;

    BST()
    {
        root = NULL;
    }

    void CreateTree(int pre[], int len)
    {
        stack<Node*> st;
        root = new Node(pre[0]);
        st.push(root);

        for (int i = 1; i < len; i++)
        {
            Node* temp = NULL;
            Node* newNode = new Node(pre[i]);

            while (!st.empty() && pre[i] > st.top()->data)
            {
                temp = st.top();
                st.pop();
            }

            if (temp != NULL)
            {
                temp->right = newNode;
            }
            else
            {
                st.top()->left = newNode;
            }

            st.push(newNode);
        }
    }

    void Create(int pre[],int len)
    {
        stack<Node*> st;
        root = new Node(pre[0]);

        Node *p = root;

        for (int i = 1; i < len; i++)           //{30,20,10,15,25,40,50,45}
        {             
            if(p->data > pre[i])
            {
                p->left= new Node(pre[i]);
                st.push(p);
                p=p->left;  
            }

            else
            {
                while(!st.empty() &&  st.top()->data < pre[i])
                {
                    p = st.top();
                    st.pop();
                }
                p->right= new Node(pre[i]);
                p=p->right;
            }
        }
    }

    void Inorder(Node* p)
    {
        if(p)
        {
            Inorder(p->left);
            cout<<p->data<<" ,";
            Inorder(p->right);
        }
    }

};

int main()
{
    BST T;
    int Preorder[] = {30,20,10,15,25,40,50,45};
    int len = sizeof(Preorder) / sizeof(Preorder[0]);

    T.Create(Preorder,len);
    T.Inorder(T.root);
}



//Correct Code

// void Create(int pre[],int len)
// {
//     stack<Node*> st;
//     root = new Node(pre[0]);

//     Node *p = root;

//     for (int i = 1; i < len; i++)           //{30,20,10,15,25,40,50,45}
//     {
                    
//         if(p->data > pre[i])
//         {
//             p->left= new Node(pre[i]);
//             st.push(p);
//             p=p->left;  
//         }

//         else
//         {
//             while(!st.empty() &&  st.top()->data < pre[i])
//             {
//                 p = st.top();
//                 st.pop();
//             }
//             p->right= new Node(pre[i]);
//             p=p->right;
//         }
//     }
// }
#include <iostream>
using namespace std;

class Node
{
    public :
    int row;
    int col;
    int val;
    Node *next;
};

class SparseMatrix
{
    Node *head;

    public:
    SparseMatrix()
    {
        head=NULL;
    }
    SparseMatrix(int nonzero);
    //~SparseMatrix()

    void Display(int r,int c);
};

SparseMatrix::SparseMatrix(int nonzero)
{
    int r,c,v;
    head=new Node;
    cout<<"Enter Row: ";
    cin>>r;
    head->row=r;
    cout<<"Enter Column: ";
    cin>>c;
    head->col=c;
    cout<<"Enter Value: ";
    cin>>v;
    head->val=v;
    head->next=NULL;
    Node *tail = head;

    for (int i = 1; i < nonzero; i++)
    {
        Node *temp = new Node;
        cout<<"Enter Row: ";
        cin>>r;
        temp->row=r;
        cout<<"Enter Column: ";
        cin>>c;
        temp->col=c;
        cout<<"Enter Value: ";
        cin>>v;
        temp->val=v;
        temp->next=tail->next;
        tail->next=temp;
        tail=temp;
    }
}

void SparseMatrix::Display(int r,int c)
{
    Node *p=head;
    for(int i=1;i<=r;i++)
    {
        int j=1;
        while(j<=c)
        {
            if(p != NULL &&(i==p->row) && (p->col==j))
            {
                cout<<p->val<<" ";
                p=p->next;
            }
            else
            {
                cout<<"0 ";
            }
            j++;
        }
        cout<<endl;
    }
}

int main()
{
    SparseMatrix SM(3);
    SM.Display(4,4);
}


/*
#include <iostream>
using namespace std;

class Node
{
public:
    int row;
    int col;
    int val;
    Node *next;

    Node() : row(0), col(0), val(0), next(nullptr) {}
    Node(int r, int c, int v) : row(r), col(c), val(v), next(nullptr) {}
};

class SparseMatrix
{
private:
    Node *head;

public:
    SparseMatrix()
    {
        head = nullptr;
    }

    SparseMatrix(int nonzero)
    {
        head = nullptr;

        for (int i = 0; i < nonzero; i++)
        {
            int row, col, val;
            cout << "Enter Row: ";
            cin >> row;
            cout << "Enter Column: ";
            cin >> col;
            cout << "Enter Value: ";
            cin >> val;

            Node *newNode = new Node(row, col, val);

            if (head == nullptr || row < head->row || (row == head->row && col < head->col))
            {
                newNode->next = head;
                head = newNode;
            }
            else
            {
                Node *prev = nullptr;
                Node *current = head;
                while (current != nullptr && (row > current->row || (row == current->row && col > current->col)))
                {
                    prev = current;
                    current = current->next;
                }

                newNode->next = current;
                prev->next = newNode;
            }
        }
    }

    void Display(int r, int c)
    {
        Node *p = head;
        for (int i = 1; i <= r; i++)
        {
            int j = 1;
            while (j <= c)
            {
                if (p != nullptr && p->row == i && p->col == j)
                {
                    cout << p->val << " ";
                    p = p->next;
                }
                else
                {
                    cout << "0 ";
                }
                j++;
            }
            cout << endl;
        }
    }

    ~SparseMatrix()
    {
        Node *current = head;
        while (current != nullptr)
        {
            Node *temp = current;
            current = current->next;
            delete temp;
        }
    }
};

int main()
{
    SparseMatrix SM(3);
    SM.Display(4, 4);
    return 0;
}
*/
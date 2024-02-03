#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next; 
};

class CircularLL
{
    Node *head;

    public :
    CircularLL(){head=NULL;}
    CircularLL(int A[],int len);
    ~CircularLL();

    int Length();
    void Display();
    void Insert(int idx, int x);
    int Delete(int idx);
    
};

CircularLL::CircularLL(int A[],int len)
{
    head = new Node;
    head->data=A[0];
    head->next=head;
    Node* tail=head;

    for(int i=1;i<len;i++)
    {
        tail->next = new Node;
        tail=tail->next;
        tail->data=A[i];
        tail->next=head;
    }
}

int CircularLL::Length()
{
    Node* p=head;
    int len = 0;
    do
    {
        len++;
        p=p->next;

    } while (p!=head);
    return len;
    
}

void CircularLL::Display()
{
    Node* p= head;
    do
    {
        cout<<p->data<<"--> ";
        p=p->next;

    } while(p!=head);
    cout<<endl;
    
}

void CircularLL::Insert(int idx, int x)
{
    Node* temp = new Node;
    Node *p=head;
    temp->data = x;
    temp->next=NULL;

    if(idx==0)
    {
        if(head==NULL)
        {
            head=temp;
            head->next=head;
        }
        else
        {
            temp->next = head;
            while(p->next!=head)
            {
                p=p->next;
            }
            p->next=temp;
            head=temp;
        }
    }
    else
    {
        for(int i=0;i<idx-1;i++)
        {
            p=p->next;
        }
        temp->next=p->next;
        p->next=temp;
    }
}

int CircularLL::Delete(int idx)
{
    Node *p=head;
    int x=-1;
    if(idx==1)
    {
        x=head->data;
        while(p->next!=head)
        {
            p=p->next;
        }
        p->next=head->next;      //p->next = p->next->next
        delete head;
        head=p->next;
    }
    else
    {
        for(int i=1;i<idx-1;i++)
        {
            p=p->next;
        }
        x=p->next->data;
        p->next=p->next->next;
    }
    return x;
}

CircularLL::~CircularLL()
{
    Node *p=head;
    while(head)
    {
        head=head->next;
        delete p;
        p=head;
    }
}

int main()
{
    int arr[] = {3,5,7,9,11,13};
    int len = sizeof(arr)/sizeof(arr[0]);
    CircularLL L(arr,len);
    L.Display();
    cout<<L.Delete(2)<<endl;
    L.Display();
}

#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
};

class LL
{
    Node *head;

    public:
    LL(){head=NULL;}
    LL(int A[],int n);
    ~LL();
    
    void Display();
    void Insert(int index,int x);
    int Delete(int index);
    int Length();
    int Max();
};

LL::LL(int A[],int len)
{
    Node *t,*last;
    head = new Node;
    head->data=A[0];
    head->next=NULL;
    last=head;

    for(int i=1;i<len;i++)
    {
        t= new Node;
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

int LL::Length()
{
    int len = 0;
    Node *p = head;
    while(p)
    {
        p=p->next;
        len++;
    }
    return len;
}

void LL::Display()
{
    Node *p=head;
    while(p)
    {
        cout<<p->data<<"--> ";
        p=p->next;
    }
    cout<<endl;
}

int LL::Delete(int index)
{
    int x=-1;

    if(index < 1 || index > Length())
        return -1;
    
    if(index==1)
    {
        x=head->data;
        head=head->next;
    }
    else
    {
        Node *p=head;
        Node *q=NULL;
        for(int i=0;i<index-1 && p;i++)
        {
            q=p;
            p=p->next;
        }
        if(p)
        {
            q->next=p->next;
            x=p->data;
            delete p;
        }
    }
    return x;
}

void LL::Insert(int index,int x)
{
    Node *temp = new Node;
    Node *p = head;
    temp->data=x;
    temp->next=NULL;

    if(index < 1 || index > Length())
        cout<<"INVALID INDEX!";

    else if(index==0)
    {
        temp->next=head;
        head=temp;
    }
    
    else
    {
        for(int i=0;i<index-1 && p;i++)
        {
            p=p->next;
        }
        if(p)
        {
            temp->next=p->next;
            p->next=temp;
        }
        else
        {
            delete temp;
        }
    }
}

int LL::Max()
{
    Node *p=head;
    int max = 0;
    while(p)
    {
        if(p->data > max)
        {
            max = p->data;
        }
        p=p->next;
    }
    cout<<"Max Element is "<<max;
    return max;
}

LL::~LL()
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
    int arr[] = {3,5,7,9,11};
    int len = sizeof(arr)/sizeof(arr[0]);
    LL L(arr,len);
    L.Display();
    L.Insert(4,13);
    L.Display();
    L.Max();
}

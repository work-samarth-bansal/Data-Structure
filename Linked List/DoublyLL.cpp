#include <iostream>
using namespace std;

class Node
{
    public :
    Node *prev;
    int data;
    Node *next; 
};

class DoublyLL
{
    Node *head;

    public :
    DoublyLL(){head=NULL;}
    DoublyLL(int A[],int len);
    //~DoublyLL();

    int Length();
    void Display();
    void RDisplay();
    void Insert(int idx,int x);
    int Delete(int idx);
};

DoublyLL::DoublyLL(int A[],int len)
{
    head = new Node;
    head->data=A[0];
    head->prev=head->next=NULL;
    Node *last;
    last=head;

    for(int i=1;i<len;i++)
    {
        Node *temp=new Node;
        temp->data=A[i];
        temp->prev=last;
        temp->next=last->next;
        last->next=temp;
        last=temp;
    }
}

int DoublyLL::Length()
{
    int len=0;
    Node *p=head;
    while(p)
    {
        len++;
        p=p->next;
    }
    return len;
}

void DoublyLL::Display()
{
    Node *p=head;
    while(p)
    {
        cout<<p->data<<"--> ";
        p=p->next;
    }
    cout<<endl;
}

void DoublyLL::RDisplay()
{
    Node *p=head;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    while(p!=NULL)
    {
        cout<<p->data<<"--> ";
        p=p->prev;
    }
    cout<<endl;
}

void DoublyLL::Insert(int idx,int x)
{
    Node *temp=new Node;
    temp->data=x;

    if(idx==0)
    {
        if(head==NULL)
        {
            head=temp;
            head->next=head->prev=NULL;
        }
        else
        {
            temp->next=head;
            temp->prev=NULL;
            head->prev=temp;
            head=temp;
        }
    }
    else
    {
        Node *p=head;
        for(int i=0;i<idx-1 && p;i++)
        {
            p=p->next;
        }
        if(p)
        {
            temp->next=p->next;
            temp->prev=p;
            if(p->next)
            {
                p->next->prev=temp;
            }
            p->next=temp;
        }
    }
}

int DoublyLL::Delete(int idx)
{
    int x=-1;
    Node *del;
    
    if (idx == 1)
    {
        del = head;
        head = head->next;
        if (head)
            head->prev = NULL;
    }
    else
    {
        Node *p = head;
        for (int i = 1; i < idx - 1 && p; i++)
        {
            p = p->next;
        }
        if (p)
        {
            del = p->next;
            p->next = del->next;
            if (del->next)
                del->next->prev = p;
        }
    }
    x = del->data;
    delete del;
    return x;
}

int main()
{
    int arr[]={2,4,6,8,10};
    int len = sizeof(arr) / sizeof(arr[0]);
    DoublyLL L(arr,len);
    L.Display();
    cout<<L.Delete(4)<<endl;
    L.Display();

}
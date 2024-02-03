#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
}*head=NULL;

void create(int A[], int len)
{
    head = new Node;
    head->data = A[0];
    head->next = NULL;
    struct Node *tail = head;

    for (int i = 1; i < len; i++)
    {
        tail->next = new Node;
        tail = tail->next;
        tail->data = A[i];
        tail->next = NULL;
    }
}


void del(int pos)
{
    int x;
    struct Node *p,*q=NULL;
    p=head;

    if(pos==0)
    {
        x=head->data;
        head=head->next;
    }
    else
    {
        for(int i=0;i<pos-1 && p;i++)
        {
            q=p;
            p=p->next;
        }
        q->next=p->next;
        x= p->data;
        delete p;
    }
    cout<<"Deleted : "<<x<<endl;
}

void deldup()
{
    Node *p,*c;
    p=head;

    while(p)
    {
        c=p->next;
        while(c)
        {
            if(c->data==p->data)
            {
                p->next=c->next;
            }
            c=c->next;
        }
        p=p->next;
    }
}

void display()
{
    struct Node *p=head;

    while(p)
    {
        cout<<p->data<<"--> ";
        p=p->next;
    }
    cout<<"NULL"<<endl;
}

int main()
{
    int arr[] = {1,3,3,3,5,5,7,9,9,9,9,9};
    int len = sizeof(arr)/sizeof(arr[0]);
    create(arr,len);
    display();
    deldup();
    display();
}
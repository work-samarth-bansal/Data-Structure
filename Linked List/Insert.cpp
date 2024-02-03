#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
}*head=NULL;

void create(int A[],int len)
{
    head = new Node;
    head->data=A[0];
    head->next=NULL;
    struct Node *temp,*last;
    last = head;

    for(int i=1;i<len;i++)
    {
        temp = new Node;
        temp->data=A[i];
        temp->next=NULL;
        last->next=temp;
        last=temp;
    }
}

void insert_at_first(struct Node *p, int n)
{
    struct Node *temp = new Node;
    temp->data=n;
    temp->next=NULL;
    temp->next=head;
    head=temp;
}

void insert_at_last(struct Node *p, int n)
{
    struct Node *temp= new Node;
    temp->data=n;
    temp->next=NULL;

    while(p->next != NULL)
    {
        p=p->next;
    }
    p->next=temp;
}

void Insert(Node* p,int num,int idx)
{
    struct Node *temp;
    temp = new Node;
    temp->data=num;
    
    if(idx==0)
    {
        temp->next=head;
        head=temp;
    }
    else
    {
        struct Node q;
        for (int i=1 ;i<idx-1 ;i++)
        {
            p=p->next;
        }
        temp->next=p->next;
        p->next=temp;
    }
}

void Display(struct Node *p)
{
    if(p!=NULL)
    {
        cout<<p->data<<"--> ";
        Display(p->next);
    }
    else
    {
        cout<<"NULL"<<endl;
    }
}

void Sort_Insert(struct Node *p,int num)
{
    struct Node *t,*q=NULL;
    t=new Node;
    t->data=num;
    t->next=NULL;
    p=head;
    q=NULL;
    while(p && p->data<num)
    {
        q=p;
        p=p->next;
    }
    t->next=q->next;
    q->next=t; 

}

void SortedInsert(struct Node *p,int x)
{
    struct Node *t,*q=NULL;
    t=new Node;
    t->data=x;
    t->next=NULL;
    
    if(head==NULL)
        head=t;
    else
    {
        while(p && p->data<x)
        {
            q=p;
            p=p->next;
        }
        if(p==head)
        {
            t->next=head;
            head=t;
        }
        else
        {
            t->next=q->next;
            q->next=t;
        }
    }
}

void checkSorted(Node *p)
{
    bool flag = true;
    while(p->next!=NULL)
    {
        if(p->data>p->next->data)
        {
            flag = false;
        }
        p=p->next;
    }
    cout<<flag<<endl;
}

int main()
{
    int arr[] = {4,5,8,9,11};
    int len = sizeof(arr)/sizeof(int);
    create(arr,len);
    Display(head); 
    Sort_Insert(head,6);
    Display(head); 
    SortedInsert(head,3);
    Display(head);  
    checkSorted(head);
}
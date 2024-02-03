#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
}*head=NULL;

void create(int A[],int n)
{
    struct Node *t,*last;
    head=new Node;
    head->data=A[0];
    head->next=NULL;
    last = head;

    for (int i = 1; i < n; i++)
    {
        t=new Node;
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

struct Node * ISearch(struct Node *p,int key)
{
    struct Node *q;
    
    while(p!=NULL)
    {
        if(p->data == key)
        {
            q->next=p->next;
            p->next=head;
            head=p;
            return p;
        }
        q=p;
        p=p->next;
    }
    return NULL;
}

struct Node * RSearch(struct Node *p,int key)
{
    if(p==NULL)
        return NULL;
    if(p->data==key)
        return p;
    else
        return RSearch(p->next,key);
}

int main()
{
 struct Node *temp;
 int A[]={3,5,7,10,25,8,32,2};
 create(A,8);

 cout<<head->data<<endl;

 temp=ISearch(head,8);
 if(temp)
    cout<<"Key Found in LL"<<endl;
 else
    cout<<"Key Not Found in LL"<<endl;

 cout<<head->data;
}

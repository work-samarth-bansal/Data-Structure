#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
}*head=NULL;

void create(int A[],int n)
{
    struct Node *temp, *last;
    head = new Node[n];
    head->data=A[0];
    head->next=NULL;
    last=head;

    for(int i=1;i<n;i++)
    {
        temp = new Node;
        temp->data=A[i];
        temp->next=NULL;
        last->next=temp;
        last=temp;
    }
}

void Display(struct Node *p)
{
    if(p!=NULL)
    {
        cout<<p->data<<" + ";
        Display(p->next);
    }
    else
    {
        cout<<"NULL"<<endl;
    }
}

int sum(struct Node *p)
{
    if(p==NULL)
    {
        return 0;
    }
    else
    {
        return sum(p->next)+p->data;
    }
}

int count(struct Node *p)
{
    if(p!=NULL)
    {
        return count(p->next)+1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int arr[] = {1,3,5,7,9};
    create(arr,5);
    Display(head); 
    cout<<"Sum of All Elements is "<<sum(head)<<endl; 
    cout<<"Number of Elements are "<<count(head)<<endl;
}

#include <iostream>
using namespace std;

// class Node
// {
//     public :
//     Node *prev;
//     int data;
//     Node *next;   
// };

class CircularDoublyLL
{
    private:
    class Node // Make Node a private inner class
    {
        public:
            Node *prev;
            int data;
            Node *next;
    };

    Node *head;

    public :
    CircularDoublyLL(){head=NULL;}
    CircularDoublyLL(int A[],int len);
    //~CircularDoublyLL()

    int Length();
    void Display();
    void RDisplay();
    void Insert(int idx,int x);
    int Delete(int idx);
};

CircularDoublyLL::CircularDoublyLL(int A[],int len)
{
    head = new Node;
    head->prev=head;
    head->data=A[0];
    head->next=head;
    Node *tail=head;

    for(int i=1;i<len;i++)
    {
        Node* temp=new Node;
        temp->prev=tail;
        temp->data=A[i];
        temp->next=tail->next;
        tail->next=temp;
        head->prev=temp;
        tail=temp;
    }
}

void CircularDoublyLL::Display()
{
    Node *p=head;
    do
    {
        cout<<p->data<<" == ";
        p=p->next;

    }while(p!=head);
    cout<<endl;
}

void CircularDoublyLL::RDisplay()
{
    Node *p=head->prev;
    do
    {
        cout<<p->data<<" == ";
        p=p->prev;

    }while(p!=head->prev);

    cout<<endl;
}


int CircularDoublyLL::Length()
{
    int len=0;
    Node *p=head;

    do
    {
        len++;
        p=p->next;

    }while(p!=head);
    return len;
}

void CircularDoublyLL::Insert(int idx,int x)
{
    Node *p =head; 
    Node *temp = new Node;
    temp->data=x;

    if(idx==0)
    {
        if(!head)
        {
            head=temp;
            head->prev=head->next=NULL;
        }
        else
        {
            temp->next=head;
            head->prev=temp;
            while(p->next!=head)
            {
                p=p->next;
            }
            p->next=temp;
            temp->prev=p;
            head=temp;
        }
    }
    else
    {
        for(int i=1;i<idx && p;i++)
        {
            p=p->next;
        }
        temp->next=p->next;
        p->next->prev=temp;
        p->next=temp;
        temp->prev=p;
    }
    
}

int CircularDoublyLL::Delete(int idx)
{
    int x=-1;
    Node* del;

    if(idx==1)
    {
        del = head;
        x = del->data;
        head->prev->next=head->next;
        head=head->next;
        head->prev=del->prev;
    }
    else
    {
        Node *p=head;
        for(int i=1;i<idx-1;i++)
        {
            p=p->next;
        }
        del=p->next;
        x=del->data;
        p->next=del->next;
        del->next->prev=del->prev;
    }
    delete del;
    return x;
}

int main()
{
    int arr[]={2,4,6,8,10};
    int len = sizeof(arr) / sizeof(arr[0]);
    CircularDoublyLL L(arr,len);
    L.Display();
    L.RDisplay();
}
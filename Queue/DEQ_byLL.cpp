#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;

     Node(int x = 0) : data(x), next(NULL) {}
};

class Deque
{
    Node *front;
    Node *rear;

    public:

    Deque() : front(NULL), rear(NULL) {}

    bool isEmpty()
    {
        return (front==NULL);
    }

    void InsertRear(int x)
    {
        Node *temp = new Node(x);
        
        if(rear == NULL)
            front = rear = temp;
        else
        {
            rear->next=temp;
            rear=temp;
        }
    }

    void InsertFront(int x)
    {
        Node *temp = new Node(x);
        
        if(front == NULL)
            front = rear = temp;
        else
        {
            temp->next=front;
            front=temp;
        }
    }

    void DeleteRear()
    {
        if (isEmpty()) {
            cout << "Deque is empty. Cannot delete from rear." << endl;
            return;
        }

        Node *curr = front;
        Node *prev = NULL;

        while(curr->next)
        {
            prev = curr;
            curr = curr->next;
        }
        delete rear;
        rear = prev;
        rear->next=NULL;

    }

    void DeleteFront()
    {
        if (isEmpty()) {
            cout << "Deque is empty. Cannot delete from front." << endl;
            return;
        }

        Node *temp = front;
        front=front->next;
        delete temp;

    }

    int getRear()
    {
        if(rear)
            return rear->data;
        
        return -1;
    }

    int getFront()
    {
        if(front)
            return front->data;
        
        return -1;
    }

    void Display()
    {
        Node *p = front;

        while(p)
        {
            cout<<p->data;
            if(p->next)
                cout<<" << ";
            p=p->next;
        }
        cout<<endl;
    }

    ~Deque() 
    {
        while (!isEmpty()) 
        {
            DeleteFront();
        }
    }
    
};

int main()
{
    Deque dq;

    dq.InsertRear(5);
    dq.InsertFront(10);
    dq.InsertRear(15);
    dq.InsertFront(20);
    dq.InsertRear(25);
    //dq.InsertFront(30);
    dq.Display();

    dq.DeleteFront();
    dq.DeleteRear();
    dq.Display();

    dq.InsertRear(30);
    dq.Display();
}

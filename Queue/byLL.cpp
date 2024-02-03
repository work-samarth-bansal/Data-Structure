#include <iostream>
using namespace std;

class Node
{
    public :
    int data;
    Node *next;

    Node() : data(INT16_MIN) , next(NULL) {}
    Node(int val) : data(val) , next(NULL) {} 
};

class Queue
{
    Node *front;
    Node *rear;

    public :

    Queue()
    {
        front = rear = NULL;
    }

    bool isEmpty()
    {
        return (front==NULL);
    }

    bool isFull()
    {
        Node *temp = new Node;
        cout<<temp;
        return (temp==NULL);
    }

    void Enqueue(int x)
    {
        Node *temp = new Node;
        temp->data = x;
        temp->next = NULL;

        if(rear==NULL)
        {
            front = rear = temp;
        }
        else
        {
            rear->next = temp;
            rear = temp;
        }
    }

    int Dequeue()
    {
        int x = -1;
        if(front)
        {
            x = front->data;
            Node *temp = front;
            front = front->next;
            delete temp;
        }
        else
            cout<<"Queue is Empty";

        return x;
    }

    int Size()
    {
        int size = 0;
        Node *temp = front;

        while(temp)
        {
            size++;
            temp= temp->next;
        }

        return size;
    }

    int Peek(int n = 1)
    {
        Node *temp = front;

        for(int i=1; i<n; i++)
        {
            temp= temp->next;
        }

        return temp->data;
    }

    void Display()
    {
        Node *temp = front;

        while(temp)
        {
            cout<<temp->data<<"--> ";
            temp=temp->next;
        }
        cout<<endl;
    }

    ~Queue()
    {
        Node *curr = front;
        Node *prev = NULL;

        while (curr)
        {
            prev = curr;
            curr = curr->next;
            delete prev;
        }
    }

};

int main()
{
    Queue q;

    q.Enqueue(1);
    q.Enqueue(2);
    q.Enqueue(3);
    q.Enqueue(4);
    q.Display();
    cout<<"Queue Size is : "<<q.Size()<<endl;
    cout<<endl;

    cout<<"Dequeue : "<<q.Dequeue()<<endl;
    cout<<"Dequeue : "<<q.Dequeue()<<endl;
    q.Display();
    cout<<"Front Element is : "<<q.Peek()<<endl;
    cout<<"Queue Size is : "<<q.Size()<<endl;
    cout<<q.isFull();

}

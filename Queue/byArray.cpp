#include <iostream>
using namespace std;

class Queue
{
    int front;
    int rear;
    int *data;
    int size;

    public:

    Queue(int n)
    {
        front = rear = -1;
        data = new int[n];
        size = n;
    }

    bool isEmpty()
    {
        return (front==-1 || front > rear);
    }

    bool isFull()
    {
        return (rear == size-1);
    }

    void Enqueue(int x)
    {
        if(isFull())
            cout<<"Queue is full"<<endl;
        else
        {
            if(front==-1)front=0;
            rear++;
            data[rear]=x;
        }
    }

    int Dequeue()
    {
        int x = INT32_MIN;
        if(isEmpty())
            cout<<"Queue is Already Empty"<<endl;

        else if (front == rear) 
        {
            front = rear = -1;
        } 
        else
        {
            x = data[front];
            //data[front]=0;
            front++;
        }
        return x;
    }

    int Size()
    {
        int len = 0;
        for(int i=front; i<=rear; i++)
        {
            len++;
        }
        return len;
    }

    int Peek(int n=1)
    {
        if(isEmpty())
        {
            cout<<"Queue is Already Empty"<<endl;
            return -1;
        }
        else
        {
            return data[front + n -1];
        }
    }

    void Display()
    {
        for(int i=front; i<=rear; i++)
        {
            cout<< data[i] ;
            if(i != rear)
                cout<<" , ";
        }
        cout<<endl;
    }

    ~Queue() {
        delete[] data; // Destructor to deallocate memory
    }
};

int main()
{
    Queue q(3);
    q.Enqueue(1);
    q.Enqueue(2);
    q.Enqueue(3);
    q.Display();

    cout<<"\nDequeue : "<<q.Dequeue()<<endl;
    q.Display();
    cout<<"Front Value is : "<<q.Peek()<<endl;
    cout<<"Queue Size is : "<<q.Size()<<endl;

}
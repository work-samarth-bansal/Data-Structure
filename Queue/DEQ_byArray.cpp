#include <iostream>
using namespace std;

class DoubleEndedQueue
{
    int *data;
    int size;
    int front;
    int rear;

    public:

    DoubleEndedQueue(int n=5)
    {
        data = new int [n];
        size = n;
        front = rear = -1;
    }

    bool isEmpty()
    {
        return (front==-1);
    }

    bool isFull()
    {
        return (front == 0 && rear == size - 1) || (front == rear + 1);
    }

    void InsertRear(int x)
    {
        if(isFull())
        {
            cout<<"Queue is Full"<<endl;
            return;
        }
        else
        {
            if(rear == -1)
                rear = front = 0;
            else if (rear == size -1)
                rear = 0;
            else
                rear++;
        }

        data[rear] = x;
    }

    void InsertFront(int x)
    {
        if(isFull())
        {
            cout<<"Queue is Full"<<endl;
            return;
        }
        else
        {
            if(front==-1)
                front = rear = 0;
            else if(front==0)
                front= size - 1 ;
            else
                front--;
        }
        data[front] = x;
    }

    void DeleteRear()
    {
        if(isEmpty())
            cout<<"Queue is already Empty"<<endl;
        else
        {
            if (front == rear)
                front = rear = -1;
            else if(rear == 0)
                rear = size -1 ;
            else
                rear--;
        }
    }

    void DeleteFront()
    {
        if(isEmpty())
            cout<<"Queue is already Empty"<<endl;
        
        else
        {
            if(front ==rear)
                front = rear = -1;
            else if(front == size - 1)
                front = 0;
            else
                front++;
        }
    }

    int getRear()
    {
        if(isEmpty())
        {
            cout<<"Queue is Empty"<<endl;
            return -1;
        }
        return data[rear];
    }

    int getFront()
    {
        if(isEmpty())
        {
            cout<<"Queue is Empty"<<endl;
            return -1;
        }
        return data[front];
    }

    void Display()
    {
        if (isEmpty()) {
            cout << "Queue is Empty" << endl;
            return;
        }
        int i = front;
        do
        {
            cout << data[i];
            if (i != rear)
                cout << " << ";
            i = (i + 1) % size;
        } while (i != (rear + 1) % size);
        cout << endl;
    }

};


int main()
{
    DoubleEndedQueue dq(5);
   
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

    dq.InsertRear(20);
    dq.Display();
    return 0;
}

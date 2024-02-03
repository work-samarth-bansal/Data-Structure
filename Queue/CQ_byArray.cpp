#include <iostream>
using namespace std;

class CircularQueue
{
    int front;
    int rear;
    int *data;
    int size;

    public:

    CircularQueue(int n)
    {
        front = rear = -1;
        data = new int[n];
        size = n;
    }

    bool isEmpty()
    {
        return (front==-1);
    }

    bool isFull()
    {
        return ((rear+1) % size == front);
    }

    void Enqueue(int x)
    {
        if(isFull())
            cout<<"Queue is full"<<endl;
        else
        {
            if(front==-1)front=0;
            rear = (rear+1)%size;               // Using '%' ,we can convert it into Circular Queue
            data[rear]=x;
        }
    }

    int Dequeue()
    {
        int x = INT32_MIN;
        if(isEmpty())
        {
            cout<<"Queue is Already Empty"<<endl;
        }
        else if (front == rear) 
        {
            front = rear = -1;
        } 
        else
        {
            x = data[front];
            //data[front]=0;
            front = (front+1)%size;              // ( 6 + 1 ) % 7 => 0            (size = 7)
        }
        return x;
    }

    int Size()
    {
        int len = 0;

        int i = front;
        do
        {
            len++;
            i = (i + 1) % size;
        } while (i != (rear + 1) % size);

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
            n = (front + n - 1)%size; 
            return data[n];
        }
    }

    int Display()
    {
        int i = front;
        do
        {
            cout << data[i];
            if (i != rear)
                cout << " , ";
            i = (i + 1) % size;
        } while (i != (rear + 1) % size);

        cout << " ." << endl;
    }


    ~CircularQueue() {
        delete[] data;
    }
};

int main()
{
    CircularQueue q(3);
    q.Enqueue(1);
    q.Enqueue(2);
    q.Enqueue(3);
    q.Display();
    cout<<"Dequeue : "<<q.Dequeue()<<endl;
    q.Enqueue(4);
    q.Display();
    cout<<"Front Value is : "<<q.Peek()<<endl;
    cout<<"Queue Size is : "<<q.Size()<<endl;

}
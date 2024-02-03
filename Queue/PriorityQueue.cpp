#include <iostream>
using namespace std;

class Node
{
    public :
    string data;
    int rank;
    Node *next;

    Node(string c,int p): data(c), rank(p), next(NULL) {}
};

class PriorityQueue
{
    Node *front;

    public: 

    PriorityQueue()
    {
        front = NULL;
    }

    void Enqueue(string c , int p)
    {
        Node *temp = new Node(c,p);

        if(front == NULL)
        {
            front = temp;
        }
        else
        {
            Node *curr = front; 
            Node *prev = NULL;

            int i=0;

            while(curr && p==curr->rank && c[i] == curr->data[i])           //for initial comparision of Highest Priority
            {
                i++;
            }

            while(curr && (p > curr->rank ||(p==curr->rank && c[i] > curr->data[i])))
            {
                prev = curr;
                curr = curr->next;
                
                while(curr && p==curr->rank && c[i] == curr->data[i])
                {
                    i++;
                }

            }
            if (prev) 
            {
                prev->next = temp;
                temp->next = curr; 

            } 
            else 
            {
                temp->next = front;
                front = temp;
            }
            
        }
    }

    void Dequeue()
    {
        string x ="-1";

        Node *temp = front;
        front = front->next;
        x = temp->data;
        delete temp;

        cout<<"Deleted: "<<x<<endl;

    }

    void Peek(int n =0)
    {
        Node *p=front;

        for(int i=0;i<n && p;i++)
            p=p->next;

        cout<<p->data<<endl;
    }

    void Display()
    {
        Node *p= front;
        while(p)
        {
            cout<<p->rank<<". "<<p->data<<endl;
            p=p->next;
        }

    }

    ~PriorityQueue() {
        while (front) 
        {
            Node *temp = front;
            front=front->next;
            delete temp;
        }
    }

};

int main()
{
    PriorityQueue pq;

    pq.Enqueue("bansal",1);
    pq.Enqueue("gupta",2);
    pq.Enqueue("aggarwal",1);
    pq.Enqueue("sharma",3);
    pq.Enqueue("garg",2);
    pq.Enqueue("gopal",2);
    pq.Enqueue("shan",3);
    pq.Enqueue("agarwal",1);

    cout<<"\nTop Priority is of : ";    
    pq.Peek();

    pq.Display();
}


        // while(curr && (p > curr->rank ||(p==curr->rank && c[i] > curr->data[i])))
        //     {
        //         prev = curr;
        //         curr = curr->next;
                
        //         while(curr && p==curr->rank && c[i] == curr->data[i])
        //         {
        //             i++;
        //         }

        //     }
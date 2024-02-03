#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node(int val): data(val), next(NULL) {}
};


class Insertion_Sort
{
    Node *head;

    public:

    Insertion_Sort()
    {
        head = NULL;
    }

    void Insert(int num)
    {
        Node *temp = new Node(num);

        if(head==NULL)
        {
            head = new Node(num);
            return;
        }

        if(head->data > num)
        {
            temp->next = head;
            head = temp;
            return;
        }

        Node *curr = head;
        Node *prev = curr;

        while(curr && curr->data < num)
        {
            prev = curr;
            curr = curr->next;
        }

        prev->next = temp;
        temp->next = curr;

    }

    void display()
    {
        Node *p = head;

        while(p)
        {
            cout<<p->data<<" ";
            p = p->next;
        }
        cout<<endl;
    }
};

int main()
{
    int arr[] = {1,5,9,2,4,8,3,6,7};
    int len = sizeof(arr) / sizeof(arr[0]);

    Insertion_Sort IS;
    
    for(int i=0; i<len; i++)
    {
        IS.Insert(arr[i]);
    }

    IS.display();

}

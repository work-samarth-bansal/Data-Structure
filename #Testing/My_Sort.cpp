#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node** next;
    
    Node(int val): data(val), next(new Node*[10]{}) {}

    ~Node() 
    {
        delete[] next;
    }
};

// I am trying to make Search Hashing technique
class Prototype
{
    public:

    Node **digits;

    Prototype()
    {
        digits = new Node*[10]{};
    }

    ~Prototype() {
        for (int i = 0; i < 10; ++i) 
        {
            Node* current = digits[i];

            while (current) 
            {
                Node* temp = current;
                current = current->next[i];
                delete temp;
            }
        }

        delete[] digits;
    }

    void Insert(Node*& digit, int num)
    {
        if(!digit)
            digit = new Node(num);

        // else
        // {
        //     Node *p = digit;
            
        //     while (p->next[num] != nullptr) 
        //         p = p->next[num];
            
        //     p->next[num] = new Node(num);
        // }
    }

    void Create(int arr[],int len)
    {

        for(int i=0; i<len; i++)
        {
            int copy = arr[i];

            Node **curr = digits;

            while(copy != 0)
            {
                int rem = copy % 10;

                Insert(curr[rem],rem);

                curr = curr[rem]->next;

                copy /= 10;
            }
        }
    }

    bool Search(int num)
    {
        Node **curr = digits;

        while(num !=0)
        {
            int rem = num % 10;

            if(!curr[rem])
                return false;

            curr = curr[rem]->next;

            num /= 10;
        }

        return true;
    }

};

int main()
{
    // Sample array of integers
    int arr[] = {123, 45, 678, 90, 121};
    int len = sizeof(arr) / sizeof(arr[0]);

    // Create a Prototype object and populate the hash table
    Prototype proto;
    proto.Create(arr, len);

    // Test searching for numbers
    int numToSearch = 45;
    if (proto.Search(numToSearch))
    {
        cout << numToSearch << " exists in the hash table." << endl;
    }
    else
    {
        cout << numToSearch << " does not exist in the hash table." << endl;
    }

    numToSearch = 121;
    if (proto.Search(numToSearch))
    {
        cout << numToSearch << " exists in the hash table." << endl;
    }
    else
    {
        cout << numToSearch << " does not exist in the hash table." << endl;
    }

    return 0;
}

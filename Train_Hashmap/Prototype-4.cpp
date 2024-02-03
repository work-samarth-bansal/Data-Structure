#include <iostream>

#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()

using namespace std;

class Node
{
public:
    Node** next;
    
    Node(): next(new Node*[10]{}) {}
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

    void Create(int arr[],int len)
    {

        for(int i=0; i<len; i++)
        {
            int copy = arr[i];

            Node **curr = digits;

            while(copy != -1)
            {
                int rem = copy % 10;

                if(!curr[rem])
                    curr[rem] = new Node;

                curr = curr[rem]->next;

                copy /= 10;
                
                if(copy == 0)
                {
                    if(!curr[0])
                        curr[0] = new Node;
                    copy--;
                }
            }
        }
    }

    bool Search(int num)
    {
        int x = num;
        int check = 0;

        Node **curr = digits;

        while(true)
        {
            int rem = num % 10;

            if(!curr[rem])
            {
                return false;
            }

            if(num == 0)
            {
                if(!(curr[rem]->next[0]))
                {
                    break;
                }
            }

            if(num > -1)
                curr = curr[rem]->next;

            check = check * 10 + rem;

            num /= 10;
        }
        
        return check == x;
    }
};

int main()
{
    int arr[] = {5,554,32,54,12,84};
    int len = sizeof(arr) / sizeof(arr[0]);

    // Create a Prototype object and populate the hash table
    Prototype proto;
    proto.Create(arr, len);

    // Test searching for numbers
    cout<<endl;
    cout<< proto.Search(5)<< endl;
    cout<< proto.Search(121)<< endl;
    cout<< proto.Search(554)<< endl;
    cout<< proto.Search(5)<< endl;
    cout<< proto.Search(84)<< endl;
    cout<< proto.Search(15)<< endl;
    cout<< proto.Search(311)<< endl;
    cout<< proto.Search(4)<< endl;
    cout<< proto.Search(548)<< endl;
}

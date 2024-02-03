#include <iostream>
#include <vector>
#include <random>

#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()

using namespace std;

class Node
{
public:
    int data;
    vector<Node*> next;
    
    Node(int val): data(val) {}
};

class Prototype
{
public:
    vector<Node*> digits;

    Prototype()
    {
        digits.resize(10, nullptr);
    }

    // ~Prototype() {
    //     for (int i = 0; i < 10; ++i) 
    //     {
    //         Node* current = digits[i];

    //         while (current) 
    //         {
    //             Node* temp = current;
    //             current = current->next[0];
    //             delete temp;
    //         }
    //     }
    // }

    void Create(int arr[], int len)
    {
        for (int i = 0; i < len; ++i)
        {
            int copy = arr[i];

            Node* curr = nullptr;

            while (copy != 0)
            {
                int rem = copy % 10;

                if (!curr)
                {
                    curr = new Node(rem);
                    digits[rem] = curr;
                    
                }
                else
                {
                    //cout<<arr[i]<<":"<<rem<<" --  "<<curr->next.size()<<endl;
                    while(curr->next.size() <= rem)
                    {
                        curr->next.push_back(nullptr);
                        //cout<<curr->next.size()<<" ";
                    }
                    //cout<<endl;

                    if (!curr->next[rem])
                        curr->next[rem] = new Node(rem);

                    curr = curr->next[rem];
                }

                copy /= 10;
            }
        }
    }


    void Search(int num)
    {
        int x = num;
        Node *curr = NULL;

        if(digits[num % 10])
            curr = digits[num % 10];

        else
        {
            cout << x << " not " << endl;
            return;
        }

        num /= 10;
        while (num > -1  && curr) 
        {
            int rem = num % 10;

            if (curr->next.size() <= rem) 
            {
                cout << x << " not  " << endl;
                return;
            }

            if(curr->next[rem])
                curr = curr->next[rem];
            else
            {
                cout << x << " not  " << endl;
                return;
            }

            num /= 10;
            
            if(num == 0)
                num--;
        }

        cout << x << " exists " << endl;
    }

};

int main() {

    srand(static_cast<unsigned int>(time(0))); // seed random number generator

    const int arraySize = 20; // size of the array
    int arr[arraySize]; // declare the array

    // fill the array with random numbers
    for (int i = 0; i < arraySize; ++i) {
        arr[i] = rand() % 1000 + 1; // generate random number between 1 and 100
    }

    // print the array
    for (int i = 0; i < arraySize; ++i) {
        std::cout << arr[i] << ' ';
    }

    // Create a Prototype object and populate the hash table
    Prototype proto;
    proto.Create(arr, arraySize);

    // Test searching for numbers
    cout<<endl;
    proto.Search(204);
    proto.Search(121);
    proto.Search(554);
    proto.Search(5);
    proto.Search(84);
    proto.Search(15);
    proto.Search(311);
    proto.Search(46);
    proto.Search(548);

    return 0;
}

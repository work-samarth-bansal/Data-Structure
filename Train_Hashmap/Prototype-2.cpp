#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node** next;

    Node(int val) : data(val), next(new Node*[10]{}) {}

    ~Node()
    {
        delete[] next;
    }
};

class Prototype
{
public:
    Node** digits;
    int capacity;
    int size;

    Prototype(int initialCapacity = 10) : capacity(initialCapacity), size(0)
    {
        digits = new Node*[capacity]{};
    }

    ~Prototype()
    {
        for (int i = 0; i < capacity; ++i)
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

    void Resize()
    {
        int newCapacity = capacity * 2;
        Node** newDigits = new Node*[newCapacity]{};

        for (int i = 0; i < capacity; ++i)
        {
            Node* current = digits[i];
            while (current)
            {
                Node* temp = current;
                current = current->next[i];

                int newIndex = temp->data % newCapacity;

                temp->next[i] = newDigits[newIndex];
                newDigits[newIndex] = temp;
            }
        }

        // Delete the old digits array, as well as the Node* objects it contains
        for (int i = 0; i < capacity; ++i)
        {
            Node* current = digits[i];
            while (current)
            {
                Node* temp = current;
                current = current->next[i];
                delete temp;
            }
        }

        // Delete the old digits array
        delete[] digits;

        // Update the digits array and capacity
        digits = newDigits;
        capacity = newCapacity;
    }

    void Create(int arr[], int len)
    {
        for (int i = 0; i < len; i++)
        {
            int copy = arr[i];

            Node** curr = digits;

            while (copy != 0)
            {
                int rem = copy % 10;

                if (!curr[rem])
                    curr[rem] = new Node(rem);

                curr = curr[rem]->next;

                copy /= 10;
            }

            size++;

            // Check if resizing is necessary
            if (size >= capacity * 0.75)
            {
                Resize();
            }
        }
    }

    void Search(int num)
    {
        int x = num;
        Node** curr = digits;

        while (num != 0)
        {
            int rem = num % 10;

            if (!curr[rem])
            {
                cout << x << " does not exist in the hash table." << endl;
                return;
            }

            curr = curr[rem]->next;
            num /= 10;
        }

        cout << x << " exists in the hash table." << endl;
    }
};

int main()
{
    // Sample array of integers
    int arr[] = {123, 45, 678, 90, 121, 111, 222, 333, 444, 555, 666, 777, 888, 999};
    int len = sizeof(arr) / sizeof(arr[0]);

    // Create a Prototype object and populate the hash table
    Prototype proto;
    proto.Create(arr, len);

    // Test searching for numbers
    proto.Search(45);
    proto.Search(1230);
    proto.Search(123);

    return 0;
}

#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    Node(int val): data(val) , next(NULL){}
};

class RadixSort
{
    Node** bins;

    public:

    RadixSort()
    {
        bins = nullptr;
    }

    ~RadixSort()
    {
        if (bins != nullptr)
        {
            delete[] bins;
        }
    }

    void Insert(Node*& bin, int num)
    {
        if(!bin)
            bin = new Node(num);
        
        else
        {
            Node *p = bin;
            while(p->next != NULL)
                p = p->next;

            p->next = new Node(num);
        }
    }

    int Delete(Node*& bin)
    {
        if (bin == nullptr)
        {
            return -1; // Handle empty list
        }

        Node* temp = bin;
        int x = bin->data;
        bin = bin->next;
        
        delete temp;  // Delete the node
        return x;
    }


    void Sort(int arr[], int len)
    {
        int max = -1;

        for(int i=0; i<len; i++)
        {
            if(arr[i]>max)
                max = arr[i];
        }

        bins = new Node *[10]{};

        int den = 1;

        while((max / den)%10 != 0)
        {
            for(int i=0; i<len; i++)
            {
                int num = (arr[i] / den) % 10;
                Insert(bins[num] ,arr[i]);
            }

            int i=0, j=0;

            while( i < max+1 )
            {
                while( bins[i] != NULL)
                {
                    arr[j++] = Delete(bins[i]);
                }
                i++;
            }

            den *= 10;
        }

    }

    void display(int arr[], int len)
    {
        for(int i=0; i<len; i++)
            cout<< arr[i] <<" ";
        
        cout<<endl;
    }
};

int main()
{
    int arr[] = {1,5,9,2,4,8,3,6,7};
    int len = sizeof(arr) / sizeof(arr[0]);

    RadixSort BS;
    
    BS.Sort(arr,len);
    BS.display(arr,len);

}
#include <iostream>
using namespace std;

class Binary_Heap
{
    public:   

    int *heap;
    int size;

    void UpHeapify(int idx)
    {
        int parent = idx/2;

        while(idx > 0 && heap[idx] > heap[parent])
        {
            swap(heap[idx],heap[parent]);
            idx = parent;
            parent = idx/2;
        }
    }


    void DownHeapity(int idx)
    {
        int largest, left, right;

        while(true)
        {
            largest = idx;
            left = idx*2;
            right = idx*2 + 1;
            
            if(left < size && heap[left] > heap[largest])
                largest = left;
            
            if(right < size && heap[right] > heap[largest])
                largest = right;
            
            if(largest != idx)
            {
                swap(heap[idx],heap[largest]);
                idx = largest;
            }
            else
            {
                break;
            }
        }
    }

    Binary_Heap(int A[] , int len)
    {
        size = len + 1;
        heap = new int[10];

        for(int i=0; i<len; i++)
            heap[i+1] = A[i];
    }


    void Insert(int x)
    {
        heap[size] = x;

        UpHeapify(size);

        size++;
    }

    int Delete(int idx = 1)
    {
        int num = heap[idx];

        heap[idx] = heap[size - 1];
        size--;

        DownHeapity(idx);

        return num;
    }

    void Heap_Sort()
    {
        while(size > 1)
        {
            cout<<Delete(1)<<" ";
        }
        cout<<endl;
    }

    void display()
    {
        for (int i = 1; i < size; i++)
        {
            cout << heap[i] << " , ";
        }
        cout << endl;
    }
};

int main()
{
    int A[] = {40,35,30,15,10,25,5};
    int len = sizeof(A) / sizeof(A[0]);

    Binary_Heap BH(A, len);
    BH.display();

    BH.Insert(20);
    BH.display();

    BH.Delete();
    BH.display();

    
    BH.Heap_Sort();

    BH.display();

    return 0;


}
#include <iostream>
using namespace std;

class Binary_Heap
{
private:
    int *heap;
    int size;

public:
    Binary_Heap(int capacity)
    {
        heap = new int[capacity];
        size = 1;
    }

    void create(int arr[], int len)
    {
        for (int i = 0; i < len; i++)
        {
            heap[i + 1] = arr[i];
        }
        size = len + 1;
        buildHeap();
    }

    void insert(int x)
    {
        if (size >= 1)
        {
            heap[size] = x;
            size++;
            heapifyUp(size - 1);
        }
    }

    int remove(int idx = 1)
    {
        if (idx >= size)
        {
            cout << "Invalid index" << endl;
            return -1;
        }
        
        int temp = heap[idx];
        heap[idx] = heap[size - 1];
        size--;

        heapifyDown(idx);

        return temp;
    }

    void heap_sort()
    {
        int originalSize = size;
        while (size > 1) // Modified condition here
        {
            // Swap the root (largest element) with the last element in the heap
            swap(heap[1], heap[size - 1]);
            size--;

            // Restore the heap property by heapifying down from the root
            heapifyDown(1);
        }
        size = originalSize; // Restore the size to its original value
    }


    void display()
    {
        for (int i = 1; i < size; i++)
        {
            cout << heap[i] << " , ";
        }
        cout << endl;
    }

private:
    void heapifyUp(int idx)
    {
        int parent = idx / 2;
        while (idx > 1 && heap[parent] < heap[idx])
        {
            swap(heap[parent], heap[idx]);
            idx = parent;
            parent = idx / 2;
        }
    }

    void heapifyDown(int idx)
    {
        int leftChild, rightChild, largest;

        while (true)
        {
            leftChild = 2 * idx;
            rightChild = 2 * idx + 1;
            largest = idx;

            if (leftChild < size && heap[leftChild] > heap[largest])
            {
                largest = leftChild;
            }

            if (rightChild < size && heap[rightChild] > heap[largest])
            {
                largest = rightChild;
            }

            if (largest != idx)
            {
                swap(heap[idx], heap[largest]);
                idx = largest;
            }
            else
            {
                break;
            }
        }
    }

    void buildHeap()
    {
        for (int i = size / 2; i >= 1; i--)
        {
            heapifyDown(i);
        }
    }
};

int main()
{
    int A[] = {40,35,30,15,10,25,5};
    int len = sizeof(A) / sizeof(A[0]);

    Binary_Heap BH(len + 1);
    BH.create(A, len);

    BH.display();
    BH.insert(20);
    BH.display();
    
    BH.heap_sort();

    BH.display();
    
    // cout<<BH.remove()<<endl;

    // BH.display();

    return 0;
}

#include <iostream>
using namespace std;

void BubbleSort(int arr[], int len)
{
    for (int i = len - 1; i >= 0 ; i--)
    {
        for (int j = 0; j < i; j++ )
        {
            // Swap if the element found is greater than the next element
            if(arr[j] > arr[j+1])
                swap(arr[j],arr[j+1]);
        }
    }
}


void InsertionSort(int arr[], int len)
{
    for (int i = 1; i < len; i++)
    {
        int key = arr[i];

        // Initailizing Previous Index
        int j = i - 1;

        // Swap if the Prevoius Element is Greater than Newly Inserted Element 
        while(j>-1 && arr[j] > key)
        {
            swap(arr[j],arr[j+1]);
            j--;
        }
    }
}


void SelectionSort(int arr[], int len)
{
    int i , j , k ;

    for (i = 0; i < len; i++)
    {
        for (j=k=i ; j < len ; j++)
        {
            if(arr[j] < arr[k])
                k = j;
        }
        swap(arr[i],arr[k]);
    }
}


int partition(int arr[], int start, int end)
{
    //Setting Starting element as Pivot
    int pivot = arr[start];
    int count = 0;

    //Finding Number of Smaller elements than Pivot (because we have to shift all Smaller element in left hand side of Pivot)
    for (int i = start+1 ; i <= end ; i++)
    {
        if(arr[i] <= pivot)
            count++;
    }

    int pivotIndex = start + count;

    // Swapping Postion of Pivot , where it belongs in Sorted Order
    swap(arr[pivotIndex],arr[start]);

    pivot = arr[pivotIndex];

   
    // (Mixed Elements) (Pivot) (Mixed Elements)
    // Swap Greater number in Left side with Smaller number in Right Side
    int i = start , j = end ;

    while(i < pivotIndex && j > pivotIndex)
    {

        while(arr[i] < pivot)                   // Finding Greater number than Pivot in Left side
        {
            i++;
        }

        while(arr[j] > pivot)                   // Finding Smaller number than Pivot in Right Side
        {
            j--;
        }

        if(arr[i] > arr[j])
            swap(arr[i++],arr[j--]);
    }
    // (Smaller Elements) (Pivot) (Greater Elements)

    // Returning Index of Partition
    return pivotIndex;

}

void QuickSort(int arr[], int start, int end)
{
    // Ending Recursion
    if(start >= end)
        return ;

    // Doing Partition
    int pivot = partition(arr, start, end);

    // Left part
    QuickSort(arr , start, pivot-1);

    // Right part
    QuickSort(arr , pivot+1 , end);
} 


void Merge(int arr[], int lower, int mid, int upper)
{
    // Making Result Array for storing Sorted elements 
    int res[upper - lower + 1];

    // Staring Index for Left part Array
    int i = lower;

    // Staring Index for Right part Array
    int j = mid + 1;

    // Staring Index for Result Array
    int k = 0;

    // Sorting and storing in Result Array
    while (i <= mid && j <= upper)
    {
        if (arr[i] > arr[j])
        {
            res[k++] = arr[j++];
        }
        else
        {
            res[k++] = arr[i++];
        }
    }

    // Appending Remaining elements from left part
    while (i <= mid)
    {
        res[k++] = arr[i++];
    }

    // Appending Remaining elements from Right part
    while (j <= upper)
    {
        res[k++] = arr[j++];
    }

    // Transfering elements from Result Array to Main Array
    for (int idx = 0; idx <= upper - lower; idx++)
    {
        arr[lower + idx] = res[idx];
    }
}

void R_MergeSort(int arr[], int lower, int upper)
{
    // Base condition
    if(lower >= upper)
    {
        return;
    }

    int mid = (lower + upper) / 2;

    // Sort Left part 
    R_MergeSort(arr, lower, mid);
    
    // Solve Right part
    R_MergeSort(arr, mid + 1, upper);

    // Merging Left and Right part
    Merge(arr , lower , mid , upper);
}

void MergeSort(int arr[], int len)
{
    int p;

    // Iterate through the array in chunks of size p
    for (p = 2; p <= len; p *= 2) // Remove int from the loop condition
    {
        // Iterate through the array with step size p
        for (int i = 0; i + p - 1 < len; i = i + p)
        {
            int lower = i;
            int upper = i + p - 1;
            int mid = (lower + upper) / 2;

            Merge(arr, lower, mid, upper);
        }
    }

    // Merge the remaining elements if any
    if (p / 2 < len)
    {
        Merge(arr, 0, p / 2 - 1, len - 1);
    }
}


void CountSort(int arr[] , int len)
{
    int max = -1;

    for (int i=0 ;i<len ;i++)
    {
        if(arr[i] > max)
            max = arr[i];
    }

    int size = max + 1;

    int HashMap[size] = {0};

    for(int i=0; i<len ; i++)
    {
        HashMap[arr[i]]++;
    }

    int i = 0 , j = 0;
    
    while(i < size)
    {
        while(HashMap[i] > 0 )
        {
            arr[j++] = i;
            HashMap[i]--;
        }
        i++;
    }
}


void ShellSort(int arr[], int len)
{
    int gap , ele;

    for( gap = len/2; gap >= 1 ; gap /= 2)
    {
        for( int i = 0; i < len ; i++)
        {
            int key = arr[i];
            int j = i - gap;

            while(j>-1 && arr[j] > key)
            {
                swap(arr[j],arr[j + gap]);
                j -= gap;
            }
        }
    }
}


void display(int arr[], int len)
{
    for(int i=0; i<len; i++)
        cout<< arr[i] <<" ";
    
    cout<<endl;
}


int main()
{
    int arr[] = {1,5,9,2,4,8,3,6,7};
    int len = sizeof(arr) / sizeof(arr[0]);

    ShellSort(arr, len);
    display(arr,len);

}
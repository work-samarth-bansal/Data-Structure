#include <iostream>
using namespace std;

bool linearSearch(int *arr, int len, int target)
{
    if(len == 0)
        return false;
    
    if(arr[0] == target)
        return true;
    
    return linearSearch(arr+1, len-1, target);
        
}

bool binarySearch(int *arr, int start ,int end, int target)
{
    if(start > end)
        return false;

    int mid = start + (end - start) / 2;

    if(arr[mid] == target)
        return true;
    
    if(arr[mid] > target)
        return binarySearch(arr, start, mid - 1, target);

    // arr[mid] < target
    return binarySearch(arr, mid + 1, end, target);

}

int main()
{
    int arr[] = {1,3,4,6,7,9};
    int len = sizeof(arr) / sizeof(arr[0]);

    cout << boolalpha << binarySearch(arr, 0, len - 1, 1) << endl;

}
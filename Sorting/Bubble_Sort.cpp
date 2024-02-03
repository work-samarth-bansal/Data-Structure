#include <iostream>
using namespace std;

//Using Bubble Sort in DECR Order
int main()
{

    int arr[] = {19,27,13,5,51,32};
    int len = sizeof(arr)/sizeof(int);

    for(int i=0;i<len;i++)
    {
        for(int j=len-1;j>i;j--)
        {
            if(arr[j]<arr[j-1])
            {
                swap(arr[j],arr[j-1]);
            }
        }
    }
    for(int i=0; i<len;i++){
        cout<<arr[i]<<endl;
    }
}

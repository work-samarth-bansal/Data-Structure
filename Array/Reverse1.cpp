#include <iostream>
using namespace std;

void rev(int arr[],int len)
{
    for(int i=0;i<len;i++)
    {
        if(i<len/2)
        {
        swap(arr[i],arr[len-1-i]);
        }
    }

    for(int i=0;i<len;i++)
    {
        cout<<arr[i]<<' ';
    }
}

int main()  
{
    int A[]={1,2,3,4,5,6,7,8,9};
    int n= sizeof(A)/sizeof(A[0]);

    rev(A,n);
}

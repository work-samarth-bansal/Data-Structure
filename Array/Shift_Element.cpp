#include <iostream>
using namespace std;

void shift(int arr[],int len)
{
    for(int i=0;i<len;i++)
    {
        arr[i]=arr[i+1];
    }
    arr[len-1]=0;

    for(int i=0;i<len;i++)
    {
        cout<<arr[i]<<' ';
    }
}

int main()
{
    int A[]={1,2,3,4,5,6,7,8,9};
    int n= sizeof(A)/sizeof(A[0]);

    shift(A,n);
}

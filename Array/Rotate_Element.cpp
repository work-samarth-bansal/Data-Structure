#include <iostream>
using namespace std;

void rotate(int arr[],int len)
{
    int temp =arr[0];
    for(int i=0;i<len;i++)
    {
        arr[i]=arr[i+1];
    }
    arr[len-1]=temp;

    for(int i=0;i<len;i++)
    {
        cout<<arr[i]<<' ';
    }
}

int main()
{
    int A[]={1,2,3,4,5,6,7,8,9};
    int n= sizeof(A)/sizeof(A[0]);

    rotate(A,n);
}

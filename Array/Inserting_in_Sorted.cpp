#include <iostream>
using namespace std;

void print(int arr[],int len)
{
    for(int i=0;i<len;i++)
    {
        cout<<arr[i]<<' ';
    }
}

void insert_sorted(int arr[],int len,int x)
{
    for(int i=0;i<len;i++)
    {
        if(arr[i]>x)
        {
            for(int j=len-1;j>i;j--)
            {
                arr[j]=arr[j-1];
            }
            arr[i]=x;
            break;
        }
    }
}

int main()
{
    int A[]={1,2,3,4,6,7,8,9,0};
    int n= sizeof(A)/sizeof(A[0]);

    insert_sorted(A,n,5);
    print(A,n);
}

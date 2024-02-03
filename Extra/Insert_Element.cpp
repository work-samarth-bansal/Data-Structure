#include <iostream>
using namespace std;

void Insert_Ele(int arr[],int len,int num,int idx)
{
    for(int i=len-1;i>idx;i--)
    {
        arr[i]=arr[i-1];
    }
    arr[idx]=num;
}

int main()
{
    int A[]={1,2,3,4,6,7,8,9,0};
    int n= sizeof(A)/sizeof(A[0]);
    int num=5;
    int index=4;

    Insert_Ele(A,n,num,index);

    for(int i=0;i<n;i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
}
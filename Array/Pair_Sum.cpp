#include <iostream>
using namespace std;

void sumpair(int arr[],int len,int x)
{
    for(int i=0;i<len;i++)
    {
        int temp=arr[i];
        for(int j=i;j<len;j++)
        {
            if(temp+arr[j]==x)
            {
                cout<<"{"<<temp<<" , "<<arr[j]<<"}"<<endl;
            }
        }
    }
}

int main()
{
    int A[]={1,2,3,4,5,6,7,8,9};
    int n= sizeof(A)/sizeof(A[0]);

    sumpair(A,n,14);
}

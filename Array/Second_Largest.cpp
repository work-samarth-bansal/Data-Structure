#include <iostream>
using namespace std;

void second_largest(int arr[],int len)
{
    int max1=arr[0];
    int max2;
    for(int i=1;i<len;i++)
    {
        if(max1 < arr[i])
        {
            max2=max1;
            max1=arr[i];
        }
    }

    cout<<max2;
    cout<<endl<<max1;
}

int main()
{
    int A[]={11,22,63,94,54,3,27,98,19};
    int n= sizeof(A)/sizeof(A[0]);

    second_largest(A,n);
}
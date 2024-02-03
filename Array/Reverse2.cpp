#include <iostream>
using namespace std;

void rev(int arr[],int l,int h)
{
    if(h>l)
    {
        swap(arr[l],arr[h]);
        return rev(arr,l+1,h-1);
    }

}

int main()
{
    int A[]={1,2,3,4,5,6,7,8,9};
    int n= sizeof(A)/sizeof(A[0]);

    rev(A,0,n-1);

    for(int i=0;i<n;i++)
    {
        cout<<A[i]<<' ';
    }
}

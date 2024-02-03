#include <iostream>
using namespace std;

int BS(int arr[],int len,int num)
{
    int l=0;
    int h=len-1;
    int mid = (l+h)/2;

    while(l<=h)
    {
        mid = (l+h)/2;
        if(arr[mid]==num)
            return mid;

        if (arr[mid]<num){
            l=mid+1;
        }
        else{
            h=mid-1;
        }
    }
    return -1;
}

int main()
{
    int A[]={1,2,3,4,5,6,7,8,9};
    int n= sizeof(A)/sizeof(A[0]);
    int num=6;

    cout<<BS(A,n,num);
}

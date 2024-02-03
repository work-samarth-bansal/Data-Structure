#include <iostream>

using namespace std;

int getmax(int arr[],int len)
{
    int temp=0;
    for(int i=0;i<len;i++)
    {
        if(arr[i]>arr[temp])
        {
            temp=i;
        }
    }
    return arr[temp];
}

int main()
{
    int j,k;
    int arr[] = {9,7,3,5,1,6,7,5,7,3,4};
    int len = sizeof(arr)/sizeof(int);
    int ele = getmax(arr,len)+1;

    int counts[ele];

    for(int i=0;i<ele;i++)
    {
        counts[i]=0;
    }

    for(int i=0;i<len;i++)
    {
        counts[arr[i]]++;
    }

    int i=j=0;
    while(i<=ele)
    {
        if(counts[i]=1)
        {
            arr[j++]=i;
            counts[i]--;
        }
        else
        {
            i++;
        }
    }

    for(int i=0; i<len;i++)
    {
        cout<<arr[i]<<endl;
    }

    return 0;
}

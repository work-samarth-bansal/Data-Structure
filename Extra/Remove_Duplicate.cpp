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

void Remove_Duplicate(int arr[],int len)
{
    int j,k;
    int ele = getmax(arr,len)+1;
    int counts[ele];
    int unique =0; 

    for(int i=0;i<ele;i++)
    {
        int c=0;
        for(int j=0;j<len;j++)
        {
            if(i==arr[j])
            {
                c+=1;
                break;
            }
        }
        counts[i]=c;
    }


    for(int i=0;i<ele;i++)
    {
        if(counts[i]==1){
            cout<<i<<" ";
            counts[i]=0;
            unique++;
        }
    }
    cout<<endl;
    cout<<"No. of Unique Elements are "<<unique;

}
int main()
{
    int arr[] = {9,7,3,5,1,6,7,5,7,3,4};
    int len = sizeof(arr)/sizeof(int);

    Remove_Duplicate(arr,len);
    return 0;
}

#include <iostream>
using namespace std;


int Insertion_in_Sorted(int arr[],int len,int num)
{

    int index;

    for(int i=0; i<len; i++)
    {
        if(num < arr[i+1])
        {
            index=i+1;

            for(int k=len-1;k>i;k--)
            {
                arr[k]=arr[k-1];
            }

            arr[index]=num;
            break;
        }
    }

    if(arr[len-1]==0){
        arr[len-1]=num;
    }

    for(int i=0; i<len;i++){
        cout<<arr[i]<<endl;
    }
}

int main()
{
    int arr[9] = {1,2,3,4,5,7,8,9};
    int len = sizeof(arr)/sizeof(int);

    Insertion_in_Sorted(arr,len,6);
    return 0;
}

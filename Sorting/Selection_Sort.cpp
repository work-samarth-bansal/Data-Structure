#include <iostream>

using namespace std;


void Selection_Sort()
{

    int arr[] = {19,27,13,5,51};
    int len = sizeof(arr)/sizeof(int);

    for(int i=0;i<len;i++){
        int temp=arr[i];
        int j=i;
        int k=j+1;

        while(k<=len){
            if(arr[k]<arr[j])
            {
                j=k;
                k++;
            }else{
                k++;
            }
        }
        arr[i]=arr[j];
        arr[j]=temp;

    }


    for(int i=0; i<len;i++){
        cout<<arr[i]<<endl;
    }
}

int main()
{


    Selection_Sort();
    return 0;
}

#include <iostream>
using namespace std;


int main(){
    
    int arr[] = {7,4,5,2};
    int len = sizeof(arr)/sizeof(int);

    for(int i=0;i<len;i++)
    {
        int temp = arr[i];
        int j=i-1;

        while(j>-1 && arr[j]>temp)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
    for(int i=0; i<len;i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}

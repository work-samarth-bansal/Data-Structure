#include <iostream>

using namespace std;


int main()
{

    int arr[] = {9,7,2,8,3,5};
    int len = sizeof(arr)/sizeof(int);

    for(int gap=len/2 ;gap>=1; gap/=2)
    {
        for(int i=gap;i<len;i++)
        {
            int temp = arr[i];
            int j=i-gap;

            while(j>-1 && arr[j]>temp)
            {
                arr[j+gap]=arr[j];
                j=j-gap;
            }
            arr[j+gap]=temp;
        }
    }

    for(int i=0; i<len;i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}
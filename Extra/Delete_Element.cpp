#include <iostream>
using namespace std;

void Delete_Ele(int arr[],int len,int num)
{
    for(int i=0;i<len;i++)
    {
        if(arr[i]==num){
            arr[i]=0;
            for(int j=i;j<len;j++){
                arr[j]=arr[j+1];
            }
        }
    }
}

//INCOMPLETE

int main()
{
    int A[]={1,2,3,4,6,7,8,6,9,0};
    int n= sizeof(A)/sizeof(A[0]);
    int num=6;

    Delete_Ele(A,n,num);

    for(int i=0;i<n;i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

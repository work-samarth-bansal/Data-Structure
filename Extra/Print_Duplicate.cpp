#include <iostream>
using namespace std;

void dup(int arr[],int len)
{
    int maxx=arr[0];
    for(int i=0;i<len;i++)
    {
        if(arr[i]>maxx)
        {
            maxx=arr[i];
        }
    }
    maxx++;

    int counts[maxx]={0};
    int dupl[10]={0};

    for(int i =0;i<len;i++)
    {
        counts[arr[i]]++;
    }

    int i=0;
    int j=0;
    while(i<maxx)
    {
        if(counts[i]>1)
        {
            dupl[j++]=i;
            i++;
        }
        else{
            i++;
        }
    }
    for(int k=0;k<10;k++){
            if(dupl[k]!=0)
                cout<<dupl[k]<<endl;
    }
}

int main(){
    int A[]={1,1,1,1,6,6,6,4,4,4,9,9,9,5,5,8,10};
    int n= sizeof(A)/sizeof(A[0]);
    dup(A,n);
}

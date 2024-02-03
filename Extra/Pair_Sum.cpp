#include <iostream>
using namespace std;

void Pair_Sum(int a,int b)
{
    if(a>b)
    {
        return ;
    }
    else
    {
        cout<<"{"<<a<<" , "<<b<<"}"<<endl;
        Pair_Sum(a+1,b-1);
    }
}

int main()
{
    int num =15;
    Pair_Sum(1,num-1);
}

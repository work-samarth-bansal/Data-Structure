#include <iostream>
using namespace std;

int fun(int n,int p)
{
    if(p>0)
    {
        return fun(n,p-1)*n;
    }
    else
    {
        return 1;
    }
}

int main (){
    int f = fun(2,6);
    cout<<f;
}
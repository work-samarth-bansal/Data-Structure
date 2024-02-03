#include <iostream>
using namespace std;

double fun(double x,double p)
{
    static double s=1;

    if(p>0)
    {
        s = 1 + x/p*s;
        return fun(x,p-1);
    }
    else
    {
        return s;
    }
}

int main (){
    cout<<fun(2,3);
}
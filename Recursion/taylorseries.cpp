#include <iostream>
using namespace std;

double fun(int x,int p)
{
    static double num=1;
    static double den=1;
    double r;

    if(p>0)
    {
        r = fun(x,p-1);
        num*=x;
        den*=p;
        r+=num/den;
        return r;
    }
    else
    {
        return 1;
    }
}

int main (){
    double f = fun(2,3);
    cout<<f;
}
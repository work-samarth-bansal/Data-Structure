#include <iostream>
using namespace std;

double sinn(double x,int n)
{
    static double p=1;
    static double f=1;
    double r;

    if(n>0)
    {
        r=sinn(x,n-1);
        p=-p*x*x;
        f=f*(n*2)*((n*2)+1);
        return r+p/f;
    }
    else
    {
        return x;
    }
}
int main(){
    double value=1;
    int terms=3;
    terms--;
    cout<<sinn(value,terms);
}

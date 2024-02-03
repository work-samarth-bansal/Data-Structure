#include <iostream>
#include <cmath>
using namespace std;

double nCx(double n,double x)
{
    if(x==0)
    {
        return 1;
    }
    if(n==x)
    {
        return 1;
    }
    else
    {
        return nCx(n-1,x-1) + nCx(n-1,x);
    }
}

void pmf(double p,double n,double x)
{
    double c = nCx(n,x);
    double pmf = c*pow(p,x)*pow(1-p,n-x);
    cout<<"pmf: "<<pmf<<endl;
}

void mean(double p,double n,double x)
{
    cout<<"mean(E): "<<n*p<<endl;
}

void var(double p,double n,double x)
{
    cout<<"var: "<<n*p*(1-p)<<endl;
}

int main()
{
    double p,x,n;
    cout<<"Enter the Probability in Success (P): ";
    cin>>p;
    cout<<"Enter the number of Trails (n): ";
    cin>>n;
    cout<<"Enter the number of Success (x): ";
    cin>>x;

    pmf(p,n,x);
    mean(p,n,x);
    var(p,n,x);
    cout<<nCx(n,x);
}

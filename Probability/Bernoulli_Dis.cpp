#include <iostream>
#include <cmath>
using namespace std;

void pmf(double p,double x)
{
    double pmf = pow(p,x)*pow(1-p,1-x);
    cout<<"pmf: "<<pmf<<endl;
}

void mean(double p,double x)
{
    cout<<"mean(E): "<<p<<endl;
}

void var(double p,double x)
{
    cout<<"var: "<<p*(1-p);
}

int main()
{
    double p,x;
    cout<<"Enter the Probability in Success: ";
    cin>>p;
    cout<<"Enter x (0/1): ";
    cin>>x;

    pmf(p,x);
    mean(p,x);
    var(p,x);
}

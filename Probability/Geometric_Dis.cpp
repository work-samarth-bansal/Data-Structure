#include <iostream>
#include <cmath>
using namespace std;

void pmf(double p,double k)
{
    double pmf = pow(1-p,k-1)*p;
    cout<<"pmf: "<<pmf<<endl;
}

void mean(double p,double k)
{
    cout<<"mean(E): "<<1/p<<endl;
}

void var(double p,double k)
{
    cout<<"var: "<<(1-p)/pow(p,2);
}

int main()
{
    double p,k;
    cout<<"Enter the Probability in Success: ";
    cin>>p;
    cout<<"Enter the success appears on kth trial: ";
    cin>>k;

    pmf(p,k);
    mean(p,k);
    var(p,k);
}

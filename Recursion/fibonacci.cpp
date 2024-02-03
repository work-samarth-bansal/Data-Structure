#include <iostream>
using namespace std;

int fib(int n)
{
    if(n==0)
    {
        return 0;
    }
    if(n==1)
    {
        return 1;
    }
    else{
        return fib(n-1)+fib(n-2);
    }
}

int main()
{
    cout<< fib(1)<<endl;
    cout<< fib(2)<<endl;
    cout<< fib(3)<<endl;
    cout<< fib(4)<<endl;
    cout<< fib(5)<<endl;
    cout<< fib(6)<<endl;
    cout<< fib(7)<<endl;
    
    /*
    int a=0;
    int b=1;
    int c;
    for (int i=0;i<5;i++)
    {
        c=a+b;
        cout<<c<<endl;
        a=b;
        b=c;
    }
    */

}
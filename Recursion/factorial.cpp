#include <iostream>
using namespace std;

int fun(int n)
{
    if(n>0)
    {
        return fun(n-1)*n;
    }
    else
    {
        return 1;
    }
}

int main (){
    int f = fun(4);
    cout<<f;
}

/*#include <iostream>
using namespace std;

int fun(int n)
{
    if(n==0)
    {
        return 1;
    }
    else
    {
        return fun(n-1)*n;
    }

}

int main (){
    int f = fun(4);
    cout<<f;
}*/

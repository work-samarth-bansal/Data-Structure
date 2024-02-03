#include <iostream>
using namespace std;

bool check2(int num)
{
    if(num == 0 || num == 1)
        return true;

    if(num % 2 != 0)
        return false;

    return check2(num/2);    

}

bool check3(int num)
{
    if(num == 0 || num == 1)
        return true;

    if(num % 3 != 0)
        return false;

    return check3(num/3);

}

int main(){

    cout<<check3(18);
}
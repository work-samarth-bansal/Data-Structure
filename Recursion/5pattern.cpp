// Given a number n, print the following pattern without using any loop.
// n, n-5, n-10, …, 0, 5, 10, …, n-5, n

// Input: n = 16
// Output: 16, 11, 6, 1, -4, 1, 6, 11, 16

// Input: n = 10
// Output: 10, 5, 0, 5, 10


#include <iostream>
using namespace std;

void pattern(int num, bool flag)
{
    static int count = 0;
    cout<<num<<" ";
    if(flag)
    {
        if(num > 0)
        {
            count++;
            pattern(num - 5,true);
        }
        else
        {
            pattern(num + 5,false);
        }
    }
    else
    {
        if(count == 1 )
            return;
        
        else
        {
            count--;
            pattern(num + 5,false);
        }
    }
}

int main()
{
    pattern(16,true);
}
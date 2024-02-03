#include <iostream>
using namespace std;

void rev(string &str, int start, int end)
{
    if(start >= end)
        return;
    
    swap(str[start],str[end]);

    rev(str, ++start, --end);
}

bool palindrome1(string str, int start, int end)
{
    if(start >= end)
        return true;
    
    if(str[start] != str[end])
        return false;

    return palindrome1(str, start+1, end-1);
}

bool palindrome2(string str, int start)
{
    if(start >= str.size() - start - 1)
        return true;
    
    if(str[start] != str[str.size() - start - 1])
        return false;

    return palindrome2(str, start+1);
}

int main(){

    string name = "samas";

    if(palindrome2(name, 0))
        cout<< "yes";
    else    
        cout<< "no";
}
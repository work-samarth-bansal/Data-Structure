#include <iostream>
using namespace std;

int main()
{
    char word[] = "racecar";
    int len = sizeof(word)/sizeof(word[0]);
    int i,j;

    for(i=0,j=len-2;i<j;i++,j--)
    {
        if(word[i] != word[j])
            break;
    }
    if(word[i] != word[j])
    {
        cout<<word<<" is not Palindrome";
    }
    else
        cout<<word<<" is Palindrome";
}

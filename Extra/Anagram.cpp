#include <iostream>
using namespace std;

int main()
{
    string s = "anagram"; 
    string t = "nagaram";

    int H[26]={0};

    for(int i = 0; i<s.length(); i++)
    {
        H[s[i]-97]++;
    }
    
    for(int i = 0; i<t.length(); i++)
    {
        H[t[i]-97]--;
    }

    bool flag = true;
    for(int i = 0; i<26; i++)
    {
        if(H[i]!=0)
        {
            flag = false;
            break;
        }
    }
    cout<<flag;
}

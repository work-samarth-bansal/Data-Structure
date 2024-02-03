#include <iostream>
using namespace std;


class Solution {
public:
    bool check(string b, string a)
    {
        if( b.size() % a.size() != 0)
            return false;

        while(b.size() >= a.size() )
        {
            if(b.substr(0,a.size()) == a)
                b = b.substr(a.size());
            else
                break;
        }

        if(b != "")
            return false;
        
        return true;
    }

    string gcdOfStrings(string str1, string str2) {        
                
        string mini = str1.size() > str2.size() ? str2 : str1;
        string maxi = str1.size() <= str2.size() ? str2 : str1;

        string ans = mini;

        int i = 2;
        int len = mini.size();
        cout<<"mini size = "<<len<<endl;
        while(true)
        {
            if(i >= len + 1)
            {
                break;
            }
            
            if(len % i == 0)
            {
                cout<<mini.substr(0,len/i)<<" <=> "<<mini.substr(len/i,len/i)<<endl;
                if(mini.substr(0,len/i) == mini.substr(len/i,len/i))
                {
                    ans = mini.substr(0,len/i);
                    cout<<i<<" . "<<ans<<endl;
                }
            }

            i++;
        }

        cout<<"maxi = "<<maxi<<"\nans = "<<ans<<endl;

        if(check(maxi,ans) == false)
            return "";        

        return ans;
    }
};
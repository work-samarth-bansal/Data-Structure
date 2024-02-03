#include <iostream>
#include <vector>
using namespace std;


int countBin(int num)
{
    int rem = 0;
    while(num != 0)
    {
        rem += num%2;

        if(num%2 == 1)
            num--;

        num/=2;
    }

    return rem;
}

class Solution {
public:
    void countBits(int n){

        vector <int> ans;
        //ans.resize(n+1);

        for(int i =0 ; i<n+1 ;i++)
        {
            ans.push_back(countBin(i));
        }
        
        for(int i =0 ; i<ans.size() ;i++)
        {
            cout<< ans[i] <<" ";
        }
    }
};

int main()
{
    Solution sol;

    sol.countBits(5);
}
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:

    void solve(vector<int> nums, vector<int> output, int index, vector<vector<int>> &ans)
    {
        if(index >= nums.size())
        {
            ans.push_back(output);
            return ;
        }
        
        //exclude
        solve(nums, output, index + 1, ans);

        //include
        output.push_back(nums[index]);
        solve(nums, output, index+1, ans);
    } 

    vector<vector<int>> subsets(vector<int>& nums){

        vector<vector<int>> ans;
        vector<int> output;

        solve(nums , output , 0 , ans);

        return ans;
    }
};

// the function solve is dealing with vectors of integers (vector<int>),
// and when you pass the output vector to the recursive calls, it is passed by value. 
// This means each recursive call gets its own copy of the output vector, 
// and modifications to it in one recursive call do not affect the output vector in the 
// other recursive call. Therefore, there is no need to manually undo changes made to output.


int main(){

    
}
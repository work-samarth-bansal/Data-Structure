#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

bool compareVectors(const std::vector<int>& a, const std::vector<int>& b)
{
    return a == b;
}

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for(int i= 0; i < nums.size(); i++)
        {
            for(int j= i+1; j < nums.size(); j++)
            {
                for(int k= j+1; k < nums.size(); k++)
                {
                    if(nums[i] + nums[j] + nums[k] == 0)
                    {
                        ans.push_back({nums[i], nums[j], nums[k]});
                    }
                }
            }
        }
        ans.erase(std::unique(ans.begin(), ans.end()), ans.end());

        sort(ans.begin(), ans.end(), compareVectors);

        auto last = unique(ans.begin(), ans.end(), compareVectors);
        ans.erase(last, ans.end());

        sort(ans.begin(), ans.end());

        return ans;
    }
};

int main()
{
    Solution sol;

    vector <int > res, ques;

}
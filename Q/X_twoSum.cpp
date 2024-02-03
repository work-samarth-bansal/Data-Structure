#include <iostream>
using namespace std;
#include <vector>
#include <stack>

int findIndex(vector<int>& vec, int target, int extra) {
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == target && i != extra) {
            return i;
        }
    }
    return -1;
}

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        vector <int> ans;
        int max = -1;

        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] > max)
                max = nums[i];
        }

        int size = max + 1;
        int hash[size];

        for(int i=0; i<size; i++)
            hash[i]=0;

        for(int i=0; i<nums.size(); i++)
        {
            hash[nums[i]]++;
        }

        int j = 0;
        while(j < size ) 
        {
            if(hash[j] > 0 && target - j >= 0 && target - j < size && hash[target - j] > 0) 
            {
                ans.push_back(findIndex(nums, j, -1));
                ans.push_back(findIndex(nums, target - j, findIndex(nums, j, -1)));
                return ans;
            }
            j++;
        }

        return ans;
    }
};

int main()
{
    Solution sol;

    vector <int > res, ques;

    ques.push_back(3);
    ques.push_back(2);
    ques.push_back(3);
    //ques.push_back(7);

    res = sol.twoSum(ques,6);

    for(int i=0; i<res.size(); i++)
    {
        cout<< res[i] << " ";
    }
    cout<<endl;
}
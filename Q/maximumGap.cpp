#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int maximumGap(std::vector<int>& nums) {
        if (nums.size() == 0 || nums.size() == 1)
            return 0;

        std::sort(nums.begin(), nums.end());

        int max_diff = 0;

        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i + 1] - nums[i] > max_diff)
                max_diff = nums[i + 1] - nums[i];
        }

        return max_diff;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = {3, 6, 9, 1};
    int maxGap = solution.maximumGap(nums);

    std::cout << "Maximum Gap: " << maxGap << std::endl;

    return 0;
}

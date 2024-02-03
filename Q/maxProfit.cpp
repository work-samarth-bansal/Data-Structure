#include <iostream>
#include <vector>
#include <climits>

class Solution {
public:
    int maxProfit(std::vector<int>& prices, int fee) {
        int buy = INT_MIN;
        int sell = 0;

        for (int price : prices) {
            buy = std::max(buy, sell - price);
            sell = std::max(sell, buy + price - fee);
        }

        return sell;
    }
};

int main() {
    Solution solution;

    // Example usage:
    std::vector<int> prices = {1, 3, 2, 8, 4, 9};
    int fee = 2;

    int result = solution.maxProfit(prices, fee);

    std::cout << "Maximum profit: " << result << std::endl;

    return 0;
}

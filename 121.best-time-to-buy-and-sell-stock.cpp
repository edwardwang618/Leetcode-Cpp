/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0, prev = 0x3f3f3f3f;
        for (int i = 0; i < prices.size(); i++) {
            res = max(res, prices[i] - prev);
            prev = min(prev, prices[i]);
        }

        return res;
    }
};
// @lc code=end


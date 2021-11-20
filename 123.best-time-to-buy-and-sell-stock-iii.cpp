/*
 * @lc app=leetcode id=123 lang=cpp
 *
 * [123] Best Time to Buy and Sell Stock III
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> f(n);
        for (int i = 1, minp = prices[0]; i < n; i++) {
            f[i] = max(f[i - 1], prices[i] - minp);
            minp = min(minp, prices[i]);
        }

        int res = 0;
        for (int i = n - 2, maxp = prices[n - 1]; i >= 0; i--) {
            res = max(res, maxp - prices[i] + f[i]);
            maxp = max(maxp, prices[i]);
        }

        return res;
    }
};
// @lc code=end


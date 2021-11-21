/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        for (int i = 1; i < prices.size(); i++)
            res += max(0, prices[i] - prices[i - 1]);
        
        return res;
    }

    // 存在a1, a2, a3, ..., b1, b2, b3, ...
    // ai买入bi卖出，ai<bi，并且[ai, bi]两两不交（某个区间的右端点和另一个区间的左端点相交可以）
    // 对于区间[a1, b1]，可以分解为[a1, a1+1],[a1+1,a1+2],...,[b1-1,b1]
    // 任意的交易方案，都可以分解为若干次长度为1的买卖区间
    // claim，任意pi > pi-1的区间[i-1,i]，都必须含在最优解里
};
// @lc code=end


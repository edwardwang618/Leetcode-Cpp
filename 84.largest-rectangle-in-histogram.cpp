/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 */

// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        stack<int> stk;
        int res = 0, n = h.size();
        for (int i = 0; i < n; i++) {
            while (stk.size() && h[stk.top()] >= h[i]) {
                int t = h[stk.top()]; stk.pop();
                res = max(res, t * (i - (stk.size() ? stk.top() : -1) - 1));
            }

            stk.push(i);
        }

        while (stk.size()) {
            int t = h[stk.top()]; stk.pop();
            res = max(res, t * (n - (stk.size() ? stk.top() : -1) - 1));
        }

        return res;
    }
};
// @lc code=end


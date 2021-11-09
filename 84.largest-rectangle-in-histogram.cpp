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
        int n = h.size(), res = 0;
        for (int i = 0; i < n; i++) {
            while (stk.size() && h[stk.top()] >= h[i]) {
                int height = h[stk.top()]; stk.pop();
                int width = i - (stk.size() ? stk.top() : -1) - 1;
                res = max(res, height * width);
            }

            stk.push(i);
        }
       
        while (stk.size()) {
            int height = h[stk.top()]; stk.pop();
            int width = n - (stk.size() ? stk.top() : -1) - 1;
            res = max(res, height * width);
        }

        return res;
    }
};
// @lc code=end


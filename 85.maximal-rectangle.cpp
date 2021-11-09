/*
 * @lc app=leetcode id=85 lang=cpp
 *
 * [85] Maximal Rectangle
 */

// @lc code=start
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;

        int m = matrix.size(), n = matrix[0].size();
        vector<int> h(n, 0);

        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) 
                h[j] = matrix[i][j] == '1' ? 1 + h[j] : 0;
            res = max(res, getArea(h));
        }

        return res;
    }

    int getArea(vector<int> &h) {
        int n = h.size();
        stack<int> stk;
        int res = 0;
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


/*
 * @lc app=leetcode id=85 lang=cpp
 *
 * [85] Maximal Rectangle
 */

// @lc code=start
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (!m) return 0;
        int n = matrix[0].size();
        if (!n) return 0;

        vector<int> h(n, 0);
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++)
                h[j] = matrix[i][j] == '0' ? 0 : h[j] + 1; 
            res = max(res, get_height(h));
        }

        return res;
    }

    int get_height(vector<int> &h) {
        int res = 0, n = h.size();
        stack<int> stk;
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


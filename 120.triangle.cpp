/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 */

// @lc code=start
class Solution {
public:
    int minimumTotal(vector<vector<int>>& A) {
        // [2]
        // [3, 4]
        // [6, 5, 7]
        // [4, 1, 8, 3]
        // 设f[i][j]是从(i, j)这个位置走到最后一行能取到的最大路径和，f[0][0]
        // f[i][j] = A[i][j] + max(f[i + 1][j], f[i + 1][j + 1])
        int n = A.size();
        vector<int> f(n, 0);
        for (int i = n - 1; i >= 0; i--)
            for (int j = 0; j <= i; j++)
                if (i == n - 1) f[j] = A[i][j];
                else f[j] = A[i][j] + min(f[j], f[j + 1]);
        
        return f[0];
    }
};
// @lc code=end


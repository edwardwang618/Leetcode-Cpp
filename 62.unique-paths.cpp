/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */

// @lc code=start
class Solution {
public:
    int uniquePaths(int m, int n) {
        // f[i][j]是从(0,0)走到(i, j)的方案数
        // f[i][j] = f[i - 1][j] + f[i][j - 1]
        int f[2][n];
        memset(f, 0, sizeof f);
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (!i || !j) f[i & 1][j] = 1;
                else f[i & 1][j] = f[i - 1 & 1][j] + f[i & 1][j - 1];
        
        return f[m - 1 & 1][n - 1];
    }
};
// @lc code=end


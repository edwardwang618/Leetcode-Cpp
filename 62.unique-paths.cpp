/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */

// @lc code=start
class Solution {
public:
    int uniquePaths(int m, int n) {
        int f[m][n];
        memset(f, 0, sizeof f);
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (!i || !j) f[i][j] = 1;
                else if (!i) f[i][j] = f[i][j - 1];
                else if (!j) f[i][j] = f[i - 1][j];
                else f[i][j] = f[i - 1][j] + f[i][j - 1];
        
        return f[m - 1][n - 1];
    }
};
// @lc code=end


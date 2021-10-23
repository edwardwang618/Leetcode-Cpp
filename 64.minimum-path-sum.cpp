/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 */

// @lc code=start
class Solution {
public:
    int minPathSum(vector<vector<int>>& A) {
        // f[i][j]是从(0,0)到(i,j)的最小路径和，
        // f[i][j] = min(f[i][j-1], f[i-1][j]) + A[i][j]
        int m = A.size(), n = A[0].size();
        int f[m][n];
        memset(f, 0, sizeof f);
        
        f[0][0] = A[0][0];

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (!i && !j) continue;
                int x = 0x3f3f3f3f;
                if (i) x = min(x, f[i - 1][j]);
                if (j) x = min(x, f[i][j - 1]);
                f[i][j] = x + A[i][j];
            }

        return f[m - 1][n - 1];
    }
};
// @lc code=end


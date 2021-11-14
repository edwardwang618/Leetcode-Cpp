/*
 * @lc app=leetcode id=96 lang=cpp
 *
 * [96] Unique Binary Search Trees
 */

// @lc code=start
class Solution {
public:
    int numTrees(int n) {
        // Catalan数
        vector<int> f(n + 1, 0);
        f[0] = 1;
        // 递推f
        for (int i = 1; i <= n; i++)
            // 枚举树根
            for (int r = 1; r <= i; r++)
                f[i] += f[r - 1] * f[i - r];

        return f[n];
    }
};
// @lc code=end


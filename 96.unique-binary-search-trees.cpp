/*
 * @lc app=leetcode id=96 lang=cpp
 *
 * [96] Unique Binary Search Trees
 */

// @lc code=start
class Solution {
public:
    int numTrees(int n) {
        int f[n + 1];
        memset(f, 0, sizeof f);
        f[0] = 1;
        for (int i = 1; i <= n; i++)
            for (int l = 0; l <= i - 1; l++) 
                f[i] += f[l] * f[i - 1 - l];
        
        return f[n];
    }
};
// @lc code=end


/*
 * @lc app=leetcode id=132 lang=cpp
 *
 * [132] Palindrome Partitioning II
 */

// @lc code=start
class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        // f[i][j]是s[i:j]是否是回文串
        // f[i][j]
        bool f[n][n];
        // f[i][j] 
        // 枚举区间长度
        for (int len = 1; len <= n; len++) 
            for (int l = 0; l + len - 1 < n; l++) {
                int r = l + len - 1;
                if (len == 1) f[l][r] = true;
                else {
                    f[l][r] = s[l] == s[r];
                    if (len > 2) f[l][r] &= f[l + 1][r - 1];
                }
            }

        vector<int> g(n, 0x3f3f3f3f);
        // g[i]是s[0:i]至少切多少次能切出每个子串都是回文串的形式
        // g[i]
        for (int i = 0; i < n; i++) {
            if (f[0][i]) g[i] = 0;
            else {
                for (int j = i; j >= 1; j--) 
                    if (f[j][i]) g[i] = min(g[i], g[j - 1] + 1);
            }
        }

        return g[n - 1];
    }
};
// @lc code=end


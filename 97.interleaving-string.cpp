/*
 * @lc app=leetcode id=97 lang=cpp
 *
 * [97] Interleaving String
 */

// @lc code=start
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(), m = s2.size();
        if (n + m != s3.size()) return false;

        bool f[2][m + 1];
        
        // 要知道f[i][j] 需要知道f[i-1][j]和f[i][j-1]
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= m; j++)
                if (!i && !j) f[i & 1][j] = true;
                else {
                    f[i & 1][j] = false;
                    if (j) f[i & 1][j] |= f[i & 1][j - 1] && s2[j - 1] == s3[i + j - 1];
                    if (i) f[i & 1][j] |= f[i - 1 & 1][j] && s1[i - 1] == s3[i + j - 1];
                }
        
        return f[n & 1][m];
    }
};
// @lc code=end


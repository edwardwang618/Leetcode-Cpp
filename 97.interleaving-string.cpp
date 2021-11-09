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

        bool f[n + 1][m + 1];
        fill(&f[0][0], &f[0][0] + (n + 1) * (m + 1), false);
        f[0][0] = true;
        for (int len = 1; len <= n + m; len++)
            for (int i = 0; i <= min(len, n); i++) {
                int j = len - i;
                if (j > m) continue;
                
                if (i == 0) f[0][j] = s2.substr(0, j) == s3.substr(0, j);
                else if (j == 0) f[i][0] = s1.substr(0, i) == s3.substr(0, i);
                else {
                    if (s1[i - 1] == s3[i + j - 1]) f[i][j] |= f[i - 1][j];
                    if (s2[j - 1] == s3[i + j - 1]) f[i][j] |= f[i][j - 1];
                }
            }

        return f[n][m];
    }
};
// @lc code=end


/*
 * @lc app=leetcode id=115 lang=cpp
 *
 * [115] Distinct Subsequences
 */

// @lc code=start
class Solution {
public:
    int numDistinct(string s, string t) {
        // f[i][j]是s的前i个字母里多少个不同的子序列等于t的前j个字母
        // f[0][0] = 1
        // f[i][j]，如果s[i - 1] != t[j - 1]，f[i][j] = f[i - 1][j]
        // 如果s[i - 1] == t[j - 1], f[i][j] = f[i - 1][j] + f[i - 1][j - 1]

        int n = s.size(), m = t.size();
        vector<vector<unsigned long>> f(n + 1, vector<unsigned long>(m + 1, 0));
        f[0][0] = 1;
        for (int i = 1; i <= n; i++)
            for (int j = 0; j <= m; j++)
                if (!j) f[i][j] = 1;
                else {
                    f[i][j] = f[i - 1][j];
                    if (s[i - 1] == t[j - 1]) f[i][j] += f[i - 1][j - 1];
                }

        return f[n][m];
    }
};
// @lc code=end


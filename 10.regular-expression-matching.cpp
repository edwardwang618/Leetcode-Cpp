/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 */

// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<bool>> f = vector<vector<bool>>(n + 1, vector<bool>(m + 1, false));
        f[0][0] = true;
        for (int i = 0; i <= n; i++)
            for (int j = 1; j <= m; j++) {
                if (p[j - 1] == '.') f[i][j] = i && f[i - 1][j - 1];
                else if (p[j - 1] != '*') f[i][j] = i && s[i - 1] == p[j - 1] && f[i - 1][j - 1];
                else {
                    f[i][j] = f[i][j - 2];
                    f[i][j] = f[i][j] | (i && (s[i - 1] == p[j - 2] || p[j - 2] == '.') && f[i - 1][j]);
                }
            }

        return f[n][m];
    }
};
// @lc code=end


/*
 * @lc app=leetcode id=44 lang=cpp
 *
 * [44] Wildcard Matching
 */

// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<bool>> f(n + 1, vector<bool>(m + 1, false));
        f[0][0] = true;
        // f[.>0][0] = false

        for (int j = 1; j <= m; j++)
            for (int i = 0; i <= n; i++) {
                if (p[j - 1] != '*') 
                    f[i][j] = i && (p[j - 1] == s[i - 1] || p[j - 1] == '?') && f[i - 1][j - 1];
                else 
                    f[i][j] = f[i][j - 1] || i && f[i - 1][j];
            }
        
        return f[n][m];
    }
};
// @lc code=end


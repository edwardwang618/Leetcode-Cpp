/*
 * @lc app=leetcode id=87 lang=cpp
 *
 * [87] Scramble String
 */

// @lc code=start
class Solution {
public:
    string s, t;
    bool isScramble(string s1, string s2) {
        s = s1;
        t = s2;
        int n = s1.size();
        vector<vector<vector<int>>> f(n, vector<vector<int>>(n, vector<int>(n + 1, -1)));
        return dfs(0, 0, n, n, f);
    }

    bool dfs(int s1, int s2, int len, int n, vector<vector<vector<int>>> &f) {
        if (~f[s1][s2][len]) return f[s1][s2][len];
        if (len == 1) return f[s1][s2][1] = s[s1] == t[s2];

        for (int i = 1; i < len; i++) {
            if (dfs(s1, s2, i, n, f) && dfs(s1 + i, s2 + i, len - i, n, f))
                return f[s1][s2][len] = 1;
            if (dfs(s1, s2 + len - i, i, n, f) && dfs(s1 + i, s2, len - i, n, f))
                return f[s1][s2][len] = 1;
        }

        return f[s1][s2][len] = 0;
    }
};
// @lc code=end


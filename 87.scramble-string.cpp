/*
 * @lc app=leetcode id=87 lang=cpp
 *
 * [87] Scramble String
 */

// @lc code=start
class Solution {
public:
    bool isScramble(string s1, string s2) {
        // f[i][j][len]是s1[i:i + len-1]能否变为s2[j:j+len-1]
        // f[0][0][n]
        // vector<bool> 
        int n = s1.size();
        bool f[n][n][n + 1];
        for (int len = 1; len <= n; len++)
            for (int i = 0; i + len - 1 < n; i++)
                for (int j = 0; j + len - 1 < n; j++) {
                    f[i][j][len] = false;

                    if (len == 1) f[i][j][1] = s1[i] == s2[j];
                    else {
                        // 枚举切割长度
                        for (int k = 1; k < len; k++) {
                            f[i][j][len] = f[i][j][len] || (f[i][j][k] && f[i + k][j + k][len - k]);
                            f[i][j][len] = f[i][j][len] || (f[i][j + len - k][k] && f[i + k][j][len - k]);
                        }
                    }

                    if (i == 0 && j == 0 && len == 8) cout << f[i][j][len] << endl;
                }
        
        return f[0][0][n];
    }

    // 记忆化搜索，
    // string s, t;
    // bool isScramble(string s1, string s2) {
    //     s = s1;
    //     t = s2;
    //     int n = s1.size();
    //     vector<vector<vector<int>>> f(n, vector<vector<int>>(n, vector<int>(n + 1, -1)));
    //     return dfs(0, 0, n, n, f);
    // }

    // // s1是s里的下标，s2是t里的下标
    // bool dfs(int s1, int s2, int len, int n, vector<vector<vector<int>>> &f) {
    //     if (~f[s1][s2][len]) return f[s1][s2][len];
    //     if (len == 1) return f[s1][s2][1] = s[s1] == t[s2];

    //     for (int i = 1; i < len; i++) {
    //         if (dfs(s1, s2, i, n, f) && dfs(s1 + i, s2 + i, len - i, n, f))
    //             return f[s1][s2][len] = 1;
    //         if (dfs(s1, s2 + len - i, i, n, f) && dfs(s1 + i, s2, len - i, n, f))
    //             return f[s1][s2][len] = 1;
    //     }

    //     return f[s1][s2][len] = 0;
    // }
};
// @lc code=end


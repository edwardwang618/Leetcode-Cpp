/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 */

// @lc code=start
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        int f[n + 1];
        fill(f, f + n + 1, 0);
        f[0] = 1;
        for (int i = 1; i <= n; i++) {
            int b = s[i - 1] - '0', a = 0;
            if (b) f[i] += f[i - 1];
            if (i >= 2) {
                a = s[i - 2] - '0';
                if (1 <= a && a <= 2 && a * 10 + b <= 26) f[i] += f[i - 2];
            }
        }

        return f[n];
    }
};
// @lc code=end


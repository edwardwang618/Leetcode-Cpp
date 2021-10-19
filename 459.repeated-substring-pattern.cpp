/*
 * @lc app=leetcode id=459 lang=cpp
 *
 * [459] Repeated Substring Pattern
 */

// @lc code=start
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        vector<int> ne = vector<int>(n + 1, 0);
        for (int i = 0, j = ne[0] = -1; i < n; )
            if (j == -1 || s[i] == s[j]) ne[++i] = ++j;
            else j = ne[j];

        return ne[n] && n % (n - ne[n]) == 0;
    }
};
// @lc code=end


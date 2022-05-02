/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start
class Solution {
public:
    bool wordBreak(string s, vector<string>& words) {
        // f[i] 是s[0:i]是否能表示出来
        // f[i] s[0:i]
        // 如果s[0:i]在words里，则true
        unordered_set<string> set;
        for (auto w : words) set.insert(w);

        int n = s.size();
        vector<bool> f(n, 0);
        // 求f
        for (int i = 0; i < n; i++) {
            // 不用分割
            if (set.count(s.substr(0, i + 1))) f[i] = true;
            else 
            // 要分割
            for (int j = i; j; j--) {
                string ss = s.substr(j, i - j + 1);
                if (set.count(ss)) {
                    f[i] = f[j - 1];
                    if (f[i]) break;
                }
            }
        }

        return f[n - 1];
    }
};
// @lc code=end


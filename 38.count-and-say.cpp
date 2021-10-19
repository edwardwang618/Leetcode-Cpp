/*
 * @lc app=leetcode id=38 lang=cpp
 *
 * [38] Count and Say
 */

// @lc code=start
class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        for (int i = 0; i < n - 1; i++) {
            string t;
            for (int j = 0; j < s.size(); j++) {
                int k = j;
                while (k < s.size() && s[k] == s[j]) k++;
                t += to_string(k - j) + s[j];
                j = k - 1;
            }

            s = t;
        }

        return s;
    }
};
// @lc code=end


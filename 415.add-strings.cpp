/*
 * @lc app=leetcode id=415 lang=cpp
 *
 * [415] Add Strings
 */

// @lc code=start
class Solution {
public:
    string addStrings(string num1, string num2) {
        string s;
        int t = 0;
        for (int i = 0; i < max(num1.size(), num2.size()); i++) {
            if (i < num1.size()) t += num1[num1.size() - 1 - i] - '0';
            if (i < num2.size()) t += num2[num2.size() - 1 - i] - '0';
            s += to_string(t % 10);
            t /= 10;
        }

        if (t) s += to_string(t);
        reverse(s.begin(), s.end());
        return s;
    }
};
// @lc code=end


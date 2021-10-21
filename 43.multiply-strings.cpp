/*
 * @lc app=leetcode id=43 lang=cpp
 *
 * [43] Multiply Strings
 */

// @lc code=start
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";

        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        vector<int> v;
        for (int i = 0; i < num1.size(); i++)
            for (int j = 0; j < num2.size(); j++) {
                int k = (num1[i] - '0') * (num2[j] - '0');
                if (i + j == v.size()) v.push_back(k);
                else v[i + j] += k;
            }

        string res;
        int t = 0;
        for (int i = 0; i < v.size(); i++) {
            t += v[i];
            res += (char) ('0' + t % 10);
            t /= 10;
        }

        if (t) res += (char) ('0' + t);

        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end


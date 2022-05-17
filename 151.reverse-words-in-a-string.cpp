/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 */

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        string res;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') {
                int j = i;
                while (j < s.size() && s[j] != ' ') j++;

                string w = s.substr(i, j - i);
                reverse(w.begin(), w.end());
                res += w + ' ';
                i = j;
            }
        }

        if (res.size()) res.pop_back();
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end


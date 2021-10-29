/*
 * @lc app=leetcode id=68 lang=cpp
 *
 * [68] Text Justification
 */

// @lc code=start
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        for (int i = 0; i < words.size(); i++) {
            int j = i + 1, len = words[i].size();
            while (j < words.size() && len + 1 + words[j].size() <= maxWidth) {
                len += 1 + words[j].size();
                j++;
            }

            string s = words[i];
            if (j == i + 1 || j == words.size()) {
                for (int k = 1; k < j - i; k++) s += " " + words[i + k];
                s += string(maxWidth - s.size(), ' ');
            } else {
                int cnt = j - i - 1, spc = maxWidth - len + cnt;
                for (int k = 1; k < j - i; k++) {
                    s += string(spc / cnt, ' ');
                    if (k <= spc % cnt) s += ' ';
                    s += words[i + k];
                }
            }

            i = j - 1;
            res.push_back(s);
        }

        return res;
    }
};
// @lc code=end


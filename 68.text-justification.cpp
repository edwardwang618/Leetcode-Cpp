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
            if (j == words.size() || j == i + 1) {
                for (int k = 1; k < j - i; k++) s += " " + words[i + k];
                s += string(maxWidth - s.size(), ' ');
            } else {
                int cnt = j - i - 1, spc = maxWidth - len + cnt;
                for (int k = 1; k <= spc % cnt; k++) s += string(spc / cnt + 1, ' ') + words[i + k];
                for (int k = spc % cnt + 1; k < 1 + cnt; k++) s += string(spc / cnt, ' ') + words[i + k];
            }

            res.push_back(s);
            i = j - 1;
        }

        return res;
    }
};
// @lc code=end


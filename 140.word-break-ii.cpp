/*
 * @lc app=leetcode id=140 lang=cpp
 *
 * [140] Word Break II
 */

// @lc code=start
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& words) {
        unordered_set<string> set;
        for (auto w : words) set.insert(w);
        vector<string> res;
        string ss = "";
        dfs(0, s, set, ss, res);
        return res;
    }

    void dfs(int i, string& s, unordered_set<string>& set, string& ss, vector<string>& res) {
        if (i == s.size()) {
            res.push_back(ss.substr(0, ss.size() - 1));
            return;
        }

        for (int j = i; j < s.size(); j++) {
            string cut = s.substr(i, j - i + 1);
            if (set.count(cut)) {
                ss += cut + ' ';
                dfs(j + 1, s, set, ss, res);
                ss = ss.substr(0, ss.size() - cut.size() - 1);
            }
        }
    }
};
// @lc code=end


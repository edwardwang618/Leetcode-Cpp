/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        static unordered_map<char, string> mp = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, 
            {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
            {'8', "tuv"}, {'9', "wxyz"}};

        vector<string> res;
        if (digits.empty()) return res;
        
        string s;
        dfs(0, digits, s, res, mp);
        return res;
    }

    void dfs(int u, string& dig, string& s, vector<string>& res, unordered_map<char, string>& mp) {
        if (u == dig.size()) {
            res.push_back(s);
            return;
        }

        for (const auto& ch : mp[dig[u]]) {
            s += ch;
            dfs(u + 1, dig, s, res, mp);
            s.pop_back();
        }
    }
};
// @lc code=end


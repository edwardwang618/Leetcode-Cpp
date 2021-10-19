/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
class Solution {
public:
    // 合法括号串的充要条件：
    // 1，左括号数等于右括号数；2，任意前缀里左括号数不少于右括号数
    // 有n个左括号的合法括号串有多少个？Catalan number
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string s;
        dfs(0, 0, n, s, res);
        return res;
    }

    void dfs(int l, int r, int n, string& s, vector<string>& res) {
        if (l == n && r == n) {
            res.push_back(s);
            return;
        }

        if (l < n) {
            s += '(';
            dfs(l + 1, r, n, s, res);
            s.pop_back();
        } 
        if (l > r) {
            s += ')';
            dfs(l, r + 1, n, s, res);
            s.pop_back();
        }
    }
};
// @lc code=end


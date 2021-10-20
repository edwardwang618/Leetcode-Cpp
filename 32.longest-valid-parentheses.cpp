/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 */

// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0;
        // char是字符，int是其下标
        stack<pair<char, int>> stk;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') stk.push({'(', i});
            else {
                if (stk.size() && stk.top().first == '(') {
                    stk.pop();
                    res = max(res, i - (stk.empty() ? -1 : stk.top().second));
                } else stk.push({')', i});
            }
        }

        return res;
    }
};
// @lc code=end


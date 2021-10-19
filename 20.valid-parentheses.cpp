/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        // 下推自动机（带栈的有限状态自动机）
        // 问，是否能构造一个有限状态自动机，只接受合法的括号串（只含小括号）？
        // 答案是不能（泵引理，pump lemma）
        unordered_map<char, char> mp = {{'(', ')'}, {'[', ']'}, {'{', '}'}};
        stack<char> stk;
        for (const auto& ch : s) {
            if (mp.count(ch)) stk.push(ch);
            else {
                if (stk.empty() || mp[stk.top()] != ch) return false;
                stk.pop();
            }
        }

        return stk.empty();
    }
};
// @lc code=end


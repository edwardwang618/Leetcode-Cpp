/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 */

// @lc code=start
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        unordered_set<string> op = {"+", "-", "*", "/"};
        for (auto &token : tokens) {
            if (op.count(token)) {
                int b = stk.top(); stk.pop();
                int a = stk.top(); stk.pop();
                int res = 0;
                if (token == "+") res = a + b;
                else if (token == "-") res = a - b;
                else if (token == "*") res = a * b;
                else if (token == "/") res = a / b;
                stk.push(res);
            } else {
                stk.push(stoi(token));
            }
        }

        return stk.top();
    }
};
// @lc code=end


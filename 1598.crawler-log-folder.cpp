/*
 * @lc app=leetcode id=1598 lang=cpp
 *
 * [1598] Crawler Log Folder
 */

// @lc code=start
class Solution {
public:
    int minOperations(vector<string>& logs) {
        int res = 0;
        for (const auto &log : logs)
            if (log == "./") continue;
            else if (log == "../") res = max(0, res - 1);
            else res++;

        return res;
    }
};
// @lc code=end


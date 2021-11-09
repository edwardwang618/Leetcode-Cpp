/*
 * @lc app=leetcode id=89 lang=cpp
 *
 * [89] Gray Code
 */

// @lc code=start
class Solution {
public:
    // [0, 1, 11, 10]
    vector<int> grayCode(int n) {
        // n = 0
        vector<int> res = {0};
        for (int i = 0; i < n; i++)
            for (int j = res.size() - 1; j >= 0; j--)
                res.push_back(res[j] | (1 << i));

        return res;
    }
};
// @lc code=end


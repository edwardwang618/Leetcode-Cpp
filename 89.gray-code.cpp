/*
 * @lc app=leetcode id=89 lang=cpp
 *
 * [89] Gray Code
 */

// @lc code=start
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res = {0};
        for (int i = 0; i < n; i++)
            for (int j = res.size() - 1; j >= 0; j--)
                res.push_back((1 << i) + res[j]);

        return res;
    }
};
// @lc code=end


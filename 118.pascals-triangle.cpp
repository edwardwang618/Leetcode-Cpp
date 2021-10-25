/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        res.push_back({1});
        for (int i = 1; i < numRows; i++) {
            res.push_back({});
            for (int j = 0; j < i + 1; j++)
                if (j == 0 || j == i) res[i].push_back(1);
                else res[i].push_back(res[i - 1][j - 1] + res[i - 1][j]);
        }

        return res;
    }
};
// @lc code=end


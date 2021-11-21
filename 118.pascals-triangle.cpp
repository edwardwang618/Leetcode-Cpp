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
            for (int j = 0; j < i; j++) res[i].push_back(!j ? 1 : res[i - 1][j - 1] + res[i - 1][j]);
            res[i].push_back(1);
        }
        
        return res;
    }
};
// @lc code=end


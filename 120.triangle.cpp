/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 */

// @lc code=start
class Solution {
public:
    int minimumTotal(vector<vector<int>>& A) {
        for (int i = A.size() - 2; i >= 0; i--) {
            for (int j = 0; j < A[i].size(); j++)
                A[i][j] += min(A[i + 1][j], A[i + 1][j + 1]);
        }

        return A[0][0];
    }
};
// @lc code=end


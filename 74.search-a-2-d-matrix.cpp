/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int l = 0, r = m * n - 1;
        if (l > r) return false;
        while (l < r) {
            int mid = l + (r - l >> 1);
            int x = mid / n, y = mid % n;
            if (matrix[x][y] >= target) r = mid;
            else l = mid + 1;
        }

        return matrix[l / n][l % n] == target;
    }
};
// @lc code=end


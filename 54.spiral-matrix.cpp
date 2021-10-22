/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        vector<int> dir = {0, 1, 0, -1, 0};
        int m = matrix.size(), n = matrix[0].size();
        int x = 0, y = 0;
        while (res.size() < m * n) {
            for (int i = 0; i < 4; i++) {
                int dx = dir[i], dy = dir[i + 1];
                while (0 <= x && x < m && 0 <= y && y < n && matrix[x][y] != 101) {
                    res.push_back(matrix[x][y]);
                    matrix[x][y] = 101;
                    x += dx;
                    y += dy;
                }

                x -= dx;
                y -= dy;
                x += dir[i + 1];
                y += dir[(i + 2) % 4];
            }
        }

        return res;
    }
};
// @lc code=end


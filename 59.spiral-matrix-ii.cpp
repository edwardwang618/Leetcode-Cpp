/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        vector<int> dir = {0, 1, 0, -1, 0};
        int x = 0, y = 0;
        int num = 1;
        while (num <= n * n) {
            for (int i = 0; i < 4; i++) {
                int dx = dir[i], dy = dir[i + 1];
                while (0 <= x && x < n && 0 <= y && y < n && res[x][y] == 0) {
                    res[x][y] = num++;
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


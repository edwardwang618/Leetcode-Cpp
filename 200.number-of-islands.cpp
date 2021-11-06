/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start
class Solution {
public:
    int d[5] = {-1, 0, 1, 0, -1};
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++)
                if (grid[i][j] == '1') {
                    res++;
                    dfs(i, j, grid);
                }

        return res;
    }

    void dfs(int x, int y, vector<vector<char>>& grid) {
        grid[x][y] = '0';
        for (int i = 0; i < 4; i++) {
            int nx = x + d[i], ny = y + d[i + 1];
            if (0 <= nx && nx < grid.size() && 0 <= ny && ny < grid[0].size() && grid[nx][ny] == '1')
                dfs(nx, ny, grid);
        }
    }
};
// @lc code=end


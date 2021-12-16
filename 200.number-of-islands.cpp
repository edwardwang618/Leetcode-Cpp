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
        int m = grid.size(), n = grid[0].size();

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == '1') {
                    bfs(i, j, grid);
                    res++;
                }

        return res;
    }

    void bfs(int x, int y, vector<vector<char>> &grid) {
        queue<pair<int, int>> q;
        q.push({x, y});
        grid[x][y] = '0';
        while (q.size()) {
            auto t = q.front(); q.pop();
            int x = t.first, y = t.second;
            for (int i = 0; i < 4; i++) {
                int nx = x + d[i], ny = y + d[i + 1];
                if (0 <= nx && nx < grid.size() && 0 <= ny && ny < grid[0].size() && grid[nx][ny] == '1') {
                    grid[nx][ny] = '0';
                    q.push({nx, ny});
                }
            }
        }
    }
};
// @lc code=end


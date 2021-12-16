/*
 * @lc app=leetcode id=1293 lang=cpp
 *
 * [1293] Shortest Path in a Grid with Obstacles Elimination
 */

// @lc code=start
class Solution {
public:

    struct State {
        int x, y, k;
    };

    int d[5] = {-1, 0, 1, 0, -1};

    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int dist[m][n][k + 1];
        memset(dist, 0x3f, sizeof dist);
        queue<State> q;
        q.push({0, 0, k});
        dist[0][0][k] = 0;

        if (m == 1 && n == 1) return 0;

        while (q.size()) {
            auto t = q.front(); q.pop();
            int x = t.x, y = t.y, k = t.k;
            for (int i = 0; i < 4; i++) {
                int nx = x + d[i], ny = y + d[i + 1];
                if (0 <= nx && nx < m && 0 <= ny && ny < n) {
                    if (!grid[nx][ny]) {
                        if (nx == m - 1 && ny == n - 1) return dist[x][y][k] + 1;
                        if (dist[nx][ny][k] < 0x3f3f3f3f) continue;
                        q.push({nx, ny, k});
                        dist[nx][ny][k] = dist[x][y][k] + 1;
                    } else if (k) {
                        if (nx == m - 1 && ny == n - 1) return dist[x][y][k] + 1;
                        if (dist[nx][ny][k - 1] < 0x3f3f3f3f) continue;
                        q.push({nx, ny, k - 1});
                        dist[nx][ny][k - 1] = dist[x][y][k] + 1;
                    }
                }
            }
        }

        return -1;
    }
};
// @lc code=end


/*
 * @lc app=leetcode id=864 lang=cpp
 *
 * [864] Shortest Path to Get All Keys
 */

// @lc code=start
class Solution {
public:
    int m, n;
    int dist[30][30][1 << 6];
    int d[5] = {-1, 0, 1, 0, -1};

    struct State {
        int x, y, key;
    };

    int shortestPathAllKeys(vector<string>& grid) {
        queue<State> q;
        m = grid.size();
        n = grid[0].size();

        memset(dist, 0x3f, sizeof dist);
        int allKeys = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                char ch = grid[i][j];
                if (ch == '@') {
                    q.push({i, j, 0});
                    dist[i][j][0] = 0;
                } else if ('a' <= ch && ch <= 'z')
                    allKeys |= 1 << (ch - 'a');
            }

        while (q.size()) {
            auto t = q.front(); q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = t.x + d[i], ny = t.y + d[i + 1];
                if (0 <= nx && nx < m && 0 <= ny && ny < n && grid[nx][ny] != '#') {
                    char k = grid[nx][ny];
                    int key = t.key;
                    if ('a' <= k && k <= 'z') key |= 1 << (k - 'a');
                    if (key == allKeys) return dist[t.x][t.y][t.key] + 1;
                    if ('A' <= k && k <= 'Z' && (t.key >> (k - 'A') & 1) == 0) continue;

                    if (dist[nx][ny][key] >= 0x3f3f3f3f) {
                        dist[nx][ny][key] = dist[t.x][t.y][t.key] + 1;
                        q.push({nx, ny, key});
                    }
                }
            }
        }

        return -1;
    }
};
// @lc code=end


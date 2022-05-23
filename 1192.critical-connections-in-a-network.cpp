/*
 * @lc app=leetcode id=1192 lang=cpp
 *
 * [1192] Critical Connections in a Network
 */

// @lc code=start
class Solution {
public:
    static const int N = 1e5 + 10;
    int h[N], e[N << 1], ne[N << 1], idx;
    int dfn[N], low[N], timestamp;

    void add(int a, int b) {
        e[idx] = b, ne[idx] = h[a], h[a] = idx++;
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        memset(h, -1, sizeof h);
        for (auto e : connections) {
            add(e[0], e[1]);
            add(e[1], e[0]);
        }

        vector<vector<int>> res;
        for (int i = 0; i < n; i++) 
            if (!dfn[i]) tarjan(i, -1, res);

        return res;
    }

    void tarjan(int u, int from, vector<vector<int>> &res) {
        dfn[u] = low[u] = ++timestamp;
        for (int i = h[u]; ~i; i = ne[i]) {
            int v = e[i];
            if (!dfn[v]) {
                tarjan(v, u, res);
                low[u] = min(low[u], low[v]);
                if (low[v] > dfn[u]) res.push_back({u, v});
            } else if (v != from) low[u] = min(low[u], dfn[v]);
        }
    }
};
// @lc code=end
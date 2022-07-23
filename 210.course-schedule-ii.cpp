/*
 * @lc app=leetcode id=210 lang=cpp
 *
 * [210] Course Schedule II
 */

// @lc code=start
class Solution {
 public:
  vector<int> findOrder(int n, vector<vector<int>>& pre) {
    int ind[n];
    fill(ind, ind + n, 0);
    unordered_map<int, vector<int>> g;
    for (auto &e : pre) {
      int a = e[0], b = e[1];
      g[b].push_back(a);
      ind[a]++;
    }
        
    queue<int> q;
    for (int i = 0; i < n; i++)
      if (!ind[i]) q.push(i);

    vector<int> res;
    while (q.size()) {
      int t = q.front(); q.pop();
      res.push_back(t);
      for (auto &x : g[t]) {
        ind[x]--;
        if (!ind[x]) q.push(x);
      }
    }

    if (res.size() < n) res = {};
    return res;
  }
};
// @lc code=end

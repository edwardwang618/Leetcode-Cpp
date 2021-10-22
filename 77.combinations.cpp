/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> v;
        dfs(1, n, k, v, res);
        return res;
    }

    void dfs(int u, int n, int k, vector<int> v, vector<vector<int>> &res) {
        if (v.size() == k) {
            res.push_back(v);
            return;
        }

        for (int i = u; i <= n; i++) {
            v.push_back(i);
            dfs(i + 1, n, k, v, res);
            v.pop_back();
        }
    }
};
// @lc code=end


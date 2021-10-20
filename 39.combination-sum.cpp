/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& A, int target) {
        vector<vector<int>> res;
        // 从大到小排序
        sort(A.begin(), A.end(), greater<int>());
        vector<int> v;
        dfs(0, target, A, v, res);
        return res;
    }

    // 当前层枚举A[u]用多少次
    void dfs(int u, int target, vector<int> &A, vector<int> &v, vector<vector<int>> &res) {
        if (u == A.size()) {
            if (!target) res.push_back(v);
            return;
        }

        for (int i = 0; i <= target / A[u]; i++) {
            dfs(u + 1, target - i * A[u], A, v, res);
            v.push_back(A[u]);
        }

        v.resize(v.size() - target / A[u] - 1);
    }
};
// @lc code=end


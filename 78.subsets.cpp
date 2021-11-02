/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> v;
        dfs(0, nums, v, res);
        return res;
    }

    // DFS要素：
    // 1. 层数的含义，以及什么时候退出
    // 2. 每层在枚举什么
    // 3. 方案在哪里
    void dfs(int u, vector<int>& nums, vector<int> &v, vector<vector<int>> &res) {
        res.push_back(v);

        if (u == nums.size()) {
            return;
        }

        for (int i = u; i < nums.size(); i++) {
            v.push_back(nums[i]);
            dfs(i + 1, nums, v, res);
            v.pop_back();
        }
    }
};
// @lc code=end


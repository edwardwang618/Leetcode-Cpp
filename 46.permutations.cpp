/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> v;
        vector<bool> used = vector<bool>(nums.size(), 0);
        dfs(0, nums, v, used, res);
        return res;
    }

    void dfs(int u, vector<int> &nums, vector<int> &v, vector<bool>used, vector<vector<int>> &res) {
        if (u == nums.size()) {
            res.push_back(v);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
            if (!used[i]) {
                used[i] = true;
                v.push_back(nums[i]);
                dfs(u + 1, nums, v, used, res);
                v.pop_back();
                used[i] = false;
            }
    }
};
// @lc code=end


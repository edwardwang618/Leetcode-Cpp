/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        vector<bool> used(nums.size(), false);
        vector<int> v;
        dfs(0, nums, used, v, res);
        return res;
    }

    void dfs(int u, vector<int> &nums, vector<bool> &used, vector<int> v, vector<vector<int>> &res) {
        if (u == nums.size()) {
            res.push_back(v);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i] || (i && nums[i] == nums[i - 1] && !used[i - 1])) continue;
            v.push_back(nums[i]);
            used[i] = true;
            dfs(u + 1, nums, used, v, res);
            used[i] = false;
            v.pop_back();
        }
    }
};
// @lc code=end


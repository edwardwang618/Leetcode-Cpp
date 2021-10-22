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


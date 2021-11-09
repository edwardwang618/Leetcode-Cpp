/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 */

// @lc code=start
class Solution {
public:
    // vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    //     sort(nums.begin(), nums.end());

    //     vector<vector<int>> res;
    //     vector<int> v;
    //     dfs(0, nums, v, res);
    //     return res;
    // }

    // void dfs(int u, vector<int> &nums, vector<int> &v, vector<vector<int>> &res) {
    //     res.push_back(v);

    //     for (int i = u; i < nums.size(); i++) {
    //         if (i > u && nums[i] == nums[i - 1]) continue;

    //         v.push_back(nums[i]);
    //         dfs(i + 1, nums, v, res);
    //         v.pop_back();
    //     }
    // }

    void dfs(int u, vector<int> &nums, vector<int> &v, vector<bool> &used, vector<vector<int>> &res) {
        if (u == nums.size()) {
            res.push_back(v);
            return;
        }

        dfs(u + 1, nums, v, used, res);

        if (u && nums[u] == nums[u - 1] && !used[u - 1]) return;

        v.push_back(nums[u]);
        used[u] = true;
        dfs(u + 1, nums, v, used, res);
        v.pop_back();
        used[u] = false;
    }
};
// @lc code=end


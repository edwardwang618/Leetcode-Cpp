/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        vector<int> v;
        vector<bool> used(nums.size(), 0);
        dfs(0, nums, v, used, res);
        return res;
    }

    void dfs(int u, vector<int> &nums, vector<int> &v, vector<bool> &used, vector<vector<int>> &res) {
        res.push_back(v);

        for (int i = u; i < nums.size(); i++) {
            if (used[i] || (i && nums[i] == nums[i - 1] && !used[i - 1])) continue;

            v.push_back(nums[i]);
            used[i] = true;
            dfs(i + 1, nums, v, used, res);
            v.pop_back();
            used[i] = false;
        }
    }

    // void dfs(int u, vector<int> &nums, vector<int> &v, vector<bool> &used, vector<vector<int>> &res) {
    //     if (u == nums.size()) {
    //         res.push_back(v);
    //         return;
    //     }

    //     dfs(u + 1, nums, v, used, res);

    //     if (u && nums[u] == nums[u - 1] && !used[u - 1]) return;

    //     v.push_back(nums[u]);
    //     used[u] = true;
    //     dfs(u + 1, nums, v, used, res);
    //     v.pop_back();
    //     used[u] = false;
    // }
};
// @lc code=end


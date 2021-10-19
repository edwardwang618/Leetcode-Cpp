/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            while (i + 1 < nums.size() && nums[i] == nums[i + 1]) i++;
            
            int l = 0, r = i - 1;
            while (l < r) {
                if (nums[l] + nums[r] < -nums[i]) l++;
                else if (nums[l] + nums[r] > -nums[i]) r--;
                else {
                    res.push_back({nums[l], nums[r], nums[i]});
                    while (l < r && nums[l] == nums[l + 1]) l++;
                    while (l < r && nums[r] == nums[r - 1]) r--;
                    l++;
                    r--;
                }
            }
        }        

        return res;
    }
};
// @lc code=end


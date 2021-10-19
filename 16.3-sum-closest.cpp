/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 */

// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res = 0, diff = 0x3f3f3f3f;
        sort(nums.begin(), nums.end());
        for (int i = 2; i < nums.size(); i++) {
            int l = 0, r = i - 1;
            while (l < r) {
                if (abs(nums[l] + nums[r] + nums[i] - target) < diff) {
                    diff = abs(nums[l] + nums[r] + nums[i] - target);
                    res = nums[l] + nums[r] + nums[i];
                }

                if (nums[l] + nums[r] + nums[i] < target) l++;
                else if (nums[l] + nums[r] + nums[i] > target) r--;
                else return res;
            }
        }

        return res;
    }
};
// @lc code=end


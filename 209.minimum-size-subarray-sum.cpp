/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res = nums.size() + 1;
        for (int i = 0, j = 0, sum = 0; i < nums.size(); i++) {
            sum += nums[i];
            while (sum >= target) {
                res = min(res, i - j + 1);
                sum -= nums[j];
                j++;
            }
        }

        return res == nums.size() + 1 ? 0 : res;
    }
};
// @lc code=end


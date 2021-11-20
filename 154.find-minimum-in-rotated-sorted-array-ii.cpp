/*
 * @lc app=leetcode id=154 lang=cpp
 *
 * [154] Find Minimum in Rotated Sorted Array II
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        int res = nums[0];
        for (int x : nums) res = min(res, x);
        return res;
    }
};
// @lc code=end


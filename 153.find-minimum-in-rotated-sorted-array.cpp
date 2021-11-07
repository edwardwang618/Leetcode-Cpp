/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + (r - l >> 1);
            if (nums[mid] < nums[0]) r = mid;
            else l = mid + 1;
        }

        if (nums[l] < nums[0]) return nums[l];
        else return nums[0];
    }
};
// @lc code=end


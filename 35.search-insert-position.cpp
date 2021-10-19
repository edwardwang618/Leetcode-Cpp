/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 */

// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        if (l > r) return 0;
        while (l < r) {
            int mid = l + (r - l >> 1);
            if (nums[mid] >= target) r = mid;
            else l = mid + 1;
        }

        return nums[l] >= target ? l : nums.size();
    }
};
// @lc code=end


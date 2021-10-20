/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        // 第一步，找下降的位置
        int l = 0, r = nums.size() - 1;
        if (l > r) return -1;
        while (l < r) {
            int mid = l + (r - l >> 1);
            if (nums[mid] < nums[0]) r = mid;
            else l = mid + 1;
        }

        if (nums[l] < nums[0]) {
            if (target >= nums[0]) r = l - 1, l = 0;
            else r = nums.size() - 1;
        } else l = 0, r = nums.size() - 1;

        while (l < r) {
            int mid = l + (r - l >> 1);
            if (nums[mid] >= target) r = mid;
            else l = mid + 1;
        }

        return nums[l] == target ? l : -1;
    }
};
// @lc code=end


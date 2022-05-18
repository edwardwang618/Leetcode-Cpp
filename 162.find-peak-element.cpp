/*
 * @lc app=leetcode id=162 lang=cpp
 *
 * [162] Find Peak Element
 */

// @lc code=start
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        if (l > r) return -1;

        while (l < r) {
            int mid = l + (r - l + 1 >> 1);
            if (!mid || nums[mid] > nums[mid - 1]) l = mid;
            else r = mid - 1;
        }

        return l;
    }
};
// @lc code=end


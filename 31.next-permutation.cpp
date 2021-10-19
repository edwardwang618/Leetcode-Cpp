/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 */

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int l = nums.size() - 1;
        while (l - 1 >= 0 && nums[l - 1] >= nums[l]) l--;
        
        if (!l) {
            reverse(nums.begin(), nums.end());
            return;
        }

        int r = nums.size() - 1;
        int k = l - 1;
        while (l < r) {
            int mid = l + (r - l + 1 >> 1);
            if (nums[mid] > nums[k]) l = mid;
            else r = mid - 1;
        }

        swap(nums[k], nums[l]);
        reverse(nums.begin() + k + 1, nums.end());
    }
};
// @lc code=end


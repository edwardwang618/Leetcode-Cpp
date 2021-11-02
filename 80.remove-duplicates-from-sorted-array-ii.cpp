/*
 * @lc app=leetcode id=80 lang=cpp
 *
 * [80] Remove Duplicates from Sorted Array II
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx = 0;
        for (int i = 0; i < nums.size(); i++) {
            int j = i;
            while (j < nums.size() && nums[j] == nums[i]) j++;

            if (j - i >= 2) nums[idx++] = nums[i];
            nums[idx++] = nums[i];

            i = j - 1;
        }

        return idx;
    }
};
// @lc code=end


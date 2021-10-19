/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx = 0;
        for (int i = 0; i < nums.size(); i++) {
            int j = i;
            while (j < nums.size() && nums[j] == nums[i]) j++;
            nums[idx++] = nums[j - 1];
            i = j - 1;
        }

        return idx;
    }
};
// @lc code=end


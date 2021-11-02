/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        // 进入循环时的性质i左边是0，k右边是2，[i,j)是1
        for (int i = 0, j = 0, k = nums.size() - 1; j <= k; )
            if (!nums[j]) swap(nums[i++], nums[j++]);
            else if (nums[j] == 2) swap(nums[j], nums[k--]);
            else j++;
    }
};
// @lc code=end



/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int pos = 0;
        int l = 0, r = nums.size() - 1;
        // 判断区间是否为空
        if (l > r) return {-1, -1};
        // 找大于等于target的第一个数
        while (l < r) {
            int mid = l + (r - l >> 1);
            if (nums[mid] >= target) r = mid;
            else l = mid + 1;
        }
        // 因为有可能不存在，所以要判，如果不存在，return -1， -1
        if (nums[l] != target) return {-1, -1};
        pos = l;

        r = nums.size() -1;
        while (l < r) {
            int mid = l + (r - l + 1 >> 1);
            if (nums[mid] <= target) l = mid;
            else r = mid - 1;
        }

        return {pos, l};
    }
};
// @lc code=end


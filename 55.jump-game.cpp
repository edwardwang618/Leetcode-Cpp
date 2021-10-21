/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return true;
        for (int l = 0, r = 0; l <= r; ) {
            int far = 0;
            for (int i = l; i <= r; i++) {
                far = max(far, i + nums[i]);
                if (far >= n - 1) return true;
            }

            l = r + 1;
            r = far;
        }

        return false;
    }
};
// @lc code=end


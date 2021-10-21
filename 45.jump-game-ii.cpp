/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        int res = 0;
        int l = 0, r = 0, far = 0;
        while (l <= r) {
            res++;
            for (int i = l; i <= r; i++)
                if (i + nums[i] >= n - 1) return res;
                else far = max(far, i + nums[i]);

            l = r + 1;
            r = far;
        }

        return -1;
    }
};
// @lc code=end


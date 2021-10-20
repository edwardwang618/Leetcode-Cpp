/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        int a = 1, b = 1, c = 1;
        for (int i = 1; i < n; i++) {
            c = a + b;
            a = b;
            b = c;
        }

        return c;
    }
};
// @lc code=end


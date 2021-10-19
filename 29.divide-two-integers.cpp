/*
 * @lc app=leetcode id=29 lang=cpp
 *
 * [29] Divide Two Integers
 */

// @lc code=start
class Solution {
public:
    // 倍增法，RMQ，在最近公共祖先LCA问题里也要用倍增
    int divide(int a, int b) {
        if (a == INT_MIN && b == -1) return INT_MAX;

        long x = a, y = b;
        int sign = (x >= 0 && y >= 0) || (x < 0 && y < 0) ? 1 : -1;
        x = abs(x);
        y = abs(y);

        long res = 0;
        int k = 31;
        while (k > -1) {
            if (x >= y << k) {
                x -= y << k;
                res += 1 << k;
            }

            k--;
        }

        return res < INT_MIN || res > INT_MAX ? INT_MAX : sign * res;
    }
};
// @lc code=end


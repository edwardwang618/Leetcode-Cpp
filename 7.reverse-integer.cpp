/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */

// @lc code=start
class Solution {
public:
    int reverse(int x) {
        if (x == INT_MIN) return 0;
        int res = 0, sign = x >= 0 ? 1 : -1;
        x = abs(x);
        while (x) {
            int a = x % 10;
            if (res > (INT_MAX - a) / 10) return 0;
            res = res * 10 + a;
            x /= 10;
        }

        return sign * res;
    }
};
// @lc code=end


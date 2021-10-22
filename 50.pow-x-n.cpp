/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
public:
    double myPow(double x, int n) {
        if (n < 0) x = 1.0 / x;
        // 改成long的原因是因为有个test case里n = -2147483648
        long m = n;
        m = abs(m);
        double res = 1.0;
        while (m) {
            if (m & 1) res *= x;
            x *= x;
            m >>= 1;
        }

        return res;
    }
};
// @lc code=end


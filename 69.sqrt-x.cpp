/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        long l = 0, r = x;
        while (l < r) {
            int mid = l + (r - l + 1 >> 1);
            if (mid <= x / mid) l = mid;
            else r = mid - 1;
        }

        return l;
    }
};
// @lc code=end


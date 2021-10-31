/*
 * @lc app=leetcode id=231 lang=cpp
 *
 * [231] Power of Two
 */

// @lc code=start
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n == INT_MIN) return false;
        return n && n == lowbit(n);
    }

    int lowbit(int x) {
        return x & -x;
    }
};
// @lc code=end


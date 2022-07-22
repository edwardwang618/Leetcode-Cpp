/*
 * @lc app=leetcode id=191 lang=cpp
 *
 * [191] Number of 1 Bits
 */

// @lc code=start
class Solution {
 public:
  int hammingWeight(uint32_t n) {
    #define lowbit(x) (x & -x);
    int res = 0;
    while (n) {
      res++;
      n -= lowbit(n);
    }
    return res;
  }
};
// @lc code=end

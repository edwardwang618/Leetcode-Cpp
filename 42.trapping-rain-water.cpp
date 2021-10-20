/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& h) {
        int res = 0, l = 1, r = h.size() - 2;
        int maxL = h[0], maxR = h[h.size() - 1];
        while (l <= r) {
            if (maxL <= maxR) {
                res += max(maxL - h[l], 0);
                maxL = max(maxL, h[l]);
                l++;
            } else {
                res += max(maxR - h[r], 0);
                maxR = max(maxR, h[r]);
                r--;
            }
        }

        return res;
    }
};
// @lc code=end


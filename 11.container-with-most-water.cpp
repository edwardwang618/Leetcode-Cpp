/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& A) {
        int res = 0;
        for (int l = 0, r = A.size() - 1; l < r; ) {
            res = max(res, min(A[l], A[r]) * (r - l));
            
            if (A[l] < A[r]) l++;
            else r--;
        }

        return res;
    }
};
// @lc code=end


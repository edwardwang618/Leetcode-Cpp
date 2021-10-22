/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& A) {
        // 设f[i]是以A[i]结尾的和最大的子数组的和
        // f[0] = A[0], f[i] = max(A[i], A[i] + f[i - 1])
        int f = A[0], res = A[0];
        for (int i = 1; i < A.size(); i++) {
            f = max(A[i], f + A[i]);
            res = max(res, f);
        }

        return res;
    }
};
// @lc code=end


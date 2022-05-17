/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& A) {
        int res = INT_MIN, n = A.size();
        for (int i = 0; i < n; i++) {
            if (!A[i]) res = max(res, 0);
            else {
                int j = i;
                while (j < A.size() && A[j]) j++;
                res = max(res, max_pos(A, i, j - 1));

                i = j - 1;
            }
        }

        return res;
    }

    // A[i], ..., A[j] != 0
    int max_pos(vector<int>& A, int i, int j) {
        int res = INT_MIN;
        // 每次循环开始的时候，max_neg存的是k之前的前缀乘积的负的最大值，max_pos是。。。正的最大值
        for (int k = i, prod = 1, max_pos = 1, max_neg = INT_MIN; k <= j; k++) {
            prod *= A[k];
            res = max(res, prod);
            res = max(res, prod / max_pos);
            if (max_neg != INT_MIN)
                res = max(res, prod / max_neg);
            
            max_pos = max(max_pos, prod);
            if (prod < 0) {
                max_neg = max(max_neg, prod);
            }
        }

        return res;
    }
};
// @lc code=end


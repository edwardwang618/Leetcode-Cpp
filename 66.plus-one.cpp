/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 */

// @lc code=start
class Solution {
public:
    // 高精度加法
    vector<int> plusOne(vector<int>& A) {
        A.back()++;
        for (int i = A.size() - 1; i; i--) {
            A[i - 1] += A[i] / 10;
            A[i] %= 10;
        }

        if (A[0] >= 10) {
            A[0] %= 10;
            A.insert(A.begin(), 1);
        }
        
        return A;
    }
};
// @lc code=end


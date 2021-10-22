/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 */

// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& A) {
        reverse(A.begin(), A.end());
        A[0]++;
        for (int i = 0; i < A.size() - 1; i++) {
            A[i + 1] += A[i] / 10;
            A[i] %= 10;
        }

        if (A.back() >= 10) {
            A.back() %= 10;
            A.push_back(1);
        }

        reverse(A.begin(), A.end());
        return A;
    }
};
// @lc code=end


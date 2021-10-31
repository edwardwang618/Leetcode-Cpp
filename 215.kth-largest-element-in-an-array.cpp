/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */

// @lc code=start
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        k = nums.size() - k;
        return quick_find(nums, 0, nums.size() - 1, k);
    }

    int quick_find(vector<int> &A, int l, int r, int k) {
        int i = l, j = r, piv = A[l + (r - l >> 1)];
        while (i <= j) {
            while (A[i] < piv) i++;
            while (A[j] > piv) j--;
            if (i <= j) {
                swap(A[i], A[j]);
                i++;
                j--;
            }
        }

        if (j >= k) return quick_find(A, l, j, k);
        else if (i <= k) return quick_find(A, i, r, k);
        else return A[k];
    }
};
// @lc code=end


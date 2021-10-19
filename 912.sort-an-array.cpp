/*
 * @lc app=leetcode id=912 lang=cpp
 *
 * [912] Sort an Array
 */

// @lc code=start
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> tmp = vector<int>(n, 0);
        merge_sort(nums, 0, n - 1, tmp);
        return nums;
    }

    void merge_sort(vector<int>& A, int l, int r, vector<int>& tmp) {
        if (l >= r) return;
        int mid = l + (r - l >> 1);
        merge_sort(A, l, mid, tmp);
        merge_sort(A, mid + 1, r, tmp);

        int i = l, j = mid + 1, idx = l;
        while (i <= mid && j <= r)
            if (A[i] <= A[j]) tmp[idx++] = A[i++];
            else tmp[idx++] = A[j++];
        
        while (i <= mid) tmp[idx++] = A[i++];
        while (j <= r) tmp[idx++] = A[j++];

        for (int k = l; k <= r; k++) A[k] = tmp[k];
    }
};
// @lc code=end


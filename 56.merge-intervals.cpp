/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& A) {
        vector<vector<int>> res;
        sort(A.begin(), A.end());
        if (A.size()) res.push_back(A[0]);
        for (int i = 1; i < A.size(); i++) merge(res, A[i]);
        return res;
    }

    void merge(vector<vector<int>> &res, vector<int> &interval) {
        int l = interval[0], r = interval[1];
        auto &b = res.back();
        if (l > b[1]) res.push_back(interval);
        else b[1] = max(b[1], r);
    }
};
// @lc code=end


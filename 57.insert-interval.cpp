/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int l = 0, r = intervals.size() - 1;
        if (l > r) {
            res.push_back(newInterval);
            return res;
        }

        while (l < r) {
            int mid = l + (r - l >> 1);
            if (intervals[mid][0] >= newInterval[0]) r = mid;
            else l = mid + 1;
        }

        if (intervals[l][0] < newInterval[0]) {
            merge(intervals, newInterval);
            return intervals;
        } else {
            for (int i = 0; i < l; i++) res.push_back(intervals[i]);
            merge(res, newInterval);
            for (int i = l; i < intervals.size(); i++) merge(res, intervals[i]);
            return res;
        }
    }

    void merge(vector<vector<int>> &res, vector<int> &interval) {
        if (res.empty()) {
            res.push_back(interval);
            return;
        }
        
        int l = interval[0], r = interval[1];
        auto &b = res.back();
        if (l > b[1]) res.push_back(interval);
        else b[1] = max(b[1], r);
    }
};
// @lc code=end


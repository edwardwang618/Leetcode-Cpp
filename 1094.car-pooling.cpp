/*
 * @lc app=leetcode id=1094 lang=cpp
 *
 * [1094] Car Pooling
 */

// @lc code=start
class Solution {
public:
    // bool carPooling(vector<vector<int>>& trips, int capacity) {
    //     int r = 0;
    //     for (auto t : trips) r = max(r, t[2]);
    //     vector<int> d(r + 1, 0);
    //     for (auto t : trips) {
    //         d[t[1]] += t[0];
    //         d[t[2]] -= t[0];
    //     }

    //     if (d[0] > capacity) return false;
    //     for (int i = 0; i < r; i++) {
    //         d[i + 1] += d[i];
    //         if (d[i + 1] > capacity) return false;
    //     }

    //     return true;
    // }

    bool carPooling(vector<vector<int>>& trips, int capacity) {
        

        return true;
    }
};
// @lc code=end


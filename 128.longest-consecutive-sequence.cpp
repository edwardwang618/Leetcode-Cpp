/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        unordered_set<int> set;
        for (int x : nums) set.insert(x);

        while (set.size()) {
            int x = *set.begin();
            set.erase(x);
            int ulen = 0, dlen = 0;
            while (set.count(x + ulen + 1)) {
                ulen++;
                set.erase(x + ulen);
            }
            while (set.count(x - dlen - 1)) {
                dlen++;
                set.erase(x - dlen);
            }

            res = max(res, 1 + ulen + dlen);
        }

        return res;
    }
};
// @lc code=end


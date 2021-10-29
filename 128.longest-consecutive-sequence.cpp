/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        for (auto x : nums) set.insert(x);

        int res = 0;
        while (set.size()) {
            int x = *set.begin();
            set.erase(x);
            int ulen = 1, dlen = 1;
            while (set.count(x + ulen)) {
                set.erase(x + ulen);
                ulen++;
            }

            while (set.count(x - dlen)) {
                set.erase(x - dlen);
                dlen++;
            }
            
            res = max(res, ulen + dlen - 1);
        }

        return res;
    }
};
// @lc code=end


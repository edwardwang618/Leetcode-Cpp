/*
 * @lc app=leetcode id=137 lang=cpp
 *
 * [137] Single Number II
 */

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> cnt(32, 0);
        for (auto x : nums) {
            int idx = 0;
            while (idx <= 31) {
                cnt[idx] += (x >> idx) & 1;
                idx++;
            }
        }

        int res = 0;
        for (int i = 0; i < 32; i++) 
            res += (cnt[i] % 3) << i;

        return res;
    }
};
// @lc code=end


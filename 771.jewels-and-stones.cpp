/*
 * @lc app=leetcode id=771 lang=cpp
 *
 * [771] Jewels and Stones
 */

// @lc code=start
class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> set;
        for (auto ch : jewels) set.insert(ch);
        int res = 0;
        for (auto ch : stones) if (set.count(ch)) res++;
        return res;
    }
};
// @lc code=end


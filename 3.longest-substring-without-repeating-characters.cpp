/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        unordered_set<char> set;
        for (int i = 0, j = 0; i < s.size(); i++) {
            while (set.count(s[i])) {
                set.erase(s[j]);
                j++;
            }

            res = max(res, i - j + 1);
            set.insert(s[i]);
        }

        return res;
    }
};
// @lc code=end


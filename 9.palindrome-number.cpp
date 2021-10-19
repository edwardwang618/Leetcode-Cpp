/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (!x) return true;

        vector<int> v;
        int y = x;
        while (x) {
            v.push_back(x % 10);
            x /= 10;
        }

        for (int i = v.size() - 1; i; i--) {
            if (y % 10 != v[i]) return false;
            y /= 10;
        }

        return true;
    }
};
// @lc code=end


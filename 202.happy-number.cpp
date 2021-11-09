/*
 * @lc app=leetcode id=202 lang=cpp
 *
 * [202] Happy Number
 */

// @lc code=start
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> set;
        while (n != 1) {
            if (set.count(n)) return false;
            set.insert(n);
            int sum = 0;
            while (n) {
                int x = n % 10;
                sum += x * x;
                n /= 10;
            }

            n = sum;
        }

        return true;
    }
};
// @lc code=end


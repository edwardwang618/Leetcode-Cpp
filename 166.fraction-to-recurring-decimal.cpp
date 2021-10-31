/*
 * @lc app=leetcode id=166 lang=cpp
 *
 * [166] Fraction to Recurring Decimal
 */

// @lc code=start
class Solution {
public:
    string fractionToDecimal(int x, int y) {
        string res;
        if (x < 0 && y > 0 || x > 0 && y < 0) res += '-';
        long n = abs((long) x), d = abs((long) y);
        res += to_string(n / d);
        n %= d;
        if (!n) return res;

        res += '.';
        unordered_map<long, int> mp;
        while (n && !mp.count(n)) {
            mp[n] = res.size();
            res += to_string(n * 10 / d);
            n = n * 10 % d;
        }

        if (n) {
            res.insert(mp[n], "(");
            res += ')';
        }

        return res;
    }
};
// @lc code=end


/*
 * @lc app=leetcode id=1869 lang=cpp
 *
 * [1869] Longer Contiguous Segments of Ones than Zeros
 */

// @lc code=start
class Solution {
public:
    bool checkZeroOnes(string s) {
        int x0 = 0, x1 = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') {
                int j = i;
                while (j < s.size() && s[j] == '0') j++;
                x0 = max(x0, j - i);
                i = j - 1;
            } else {
                int j = i;
                while (j < s.size() && s[j] == '1') j++;
                x1 = max(x1, j - i);
                i = j - 1;
            }
        }

        return x1 > x0;
    }
};
// @lc code=end


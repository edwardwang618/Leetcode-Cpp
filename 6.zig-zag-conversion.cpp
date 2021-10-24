/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] ZigZag Conversion
 */

// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        
        int n = s.size();
        string res;
        for (int i = 0; i < numRows; i++) {
            if (i == 0 || i == numRows - 1) {
                for (int j = i; j < n; j += 2 * numRows - 2) {
                    res += s[j];
                }
            } else {
                for (int j1 = i, j2 = 2 * numRows - 2 - i; j1 < n || j2 < n; j1 += 2 * numRows - 2, j2 += 2 * numRows - 2) {
                    if (j1 < n) {
                        res += s[j1];
                    }
                    
                    if (j2 < n) {
                        res += s[j2];
                    }
                }
            }
        }
        
        return res;
    }
};
// @lc code=end


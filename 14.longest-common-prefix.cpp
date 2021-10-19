/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string res = strs[0];
        for (int i = 1; i < strs.size(); i++)
            res = lcp(res, strs[i]);
        
        return res;
    }

    string lcp(string& a, string& b) {
        string res;
        for (int i = 0; i < min(a.size(), b.size()); i++)
            if (a[i] == b[i]) res += a[i];
            else break;
        
        return res;
    }
};
// @lc code=end
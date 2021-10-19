/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 */

// @lc code=start
class Solution {
public:
    int strStr(string s, string p) {
        if (p.empty()) return 0;

        auto ne = buildNe(p);
        for (int i = 0, j = 0; i < s.size(); ) {
            if (j == -1 || s[i] == p[j]) i++, j++;
            else j = ne[j];

            if (j == p.size()) return i - j;
        }

        return -1;
    }

    vector<int> buildNe(string p) {
        int m = p.size();
        vector<int> ne = vector<int>(m, 0);
        for (int i = 0, j = ne[0] = -1; i < m - 1; ) 
            if (j == -1 || p[i] == p[j]) {
                ++i;
                ++j;
                ne[i] = p[i] != p[j] ? j : ne[j];
            } else j = ne[j];
        
        return ne;
    }
};
// @lc code=end
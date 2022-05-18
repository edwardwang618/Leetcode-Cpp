/*
 * @lc app=leetcode id=165 lang=cpp
 *
 * [165] Compare Version Numbers
 */

// @lc code=start
class Solution {
public:
    int compareVersion(string v1, string v2) {
        int i = 0, j = 0, s1 = 0, s2 = 0;
        while (i < v1.size() || j < v2.size()) {
            if (i == v1.size()) s1 = 0;
            else {
                int k = i;
                while (k < v1.size() && v1[k] != '.') k++;
                s1 = stoi(v1.substr(i, k - i));
                if (k < v1.size()) i = k + 1;
                else i = k;
            }
            if (j == v2.size()) s2 = 0;
            else {
                int k = j;
                while (k < v2.size() && v2[k] != '.') k++;
                s2 = stoi(v2.substr(j, k - j));
                if (k < v2.size()) j = k + 1;
                else j = k;
            }

            if (s1 < s2) return -1;
            if (s1 > s2) return 1;
        }
        return 0;
    }
};
// @lc code=end


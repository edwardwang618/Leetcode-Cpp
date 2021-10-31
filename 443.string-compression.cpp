/*
 * @lc app=leetcode id=443 lang=cpp
 *
 * [443] String Compression
 */

// @lc code=start
class Solution {
public:
    int compress(vector<char>& chs) {
        int idx = 0;
        for (int i = 0; i < chs.size(); i++) {
            int j = i;
            while (j < chs.size() && chs[j] == chs[i]) j++;
            chs[idx++] = chs[i];
            if (j - i > 1) {
                string s = to_string(j - i);
                for (char ch : s) chs[idx++] = ch;
            }

            i = j - 1;
        }

        return idx;
    }
};
// @lc code=end


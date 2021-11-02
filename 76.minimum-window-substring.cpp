/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";
        unordered_map<char, int> map;
        int cnt = 0;
        for (char ch : t) map[ch]++;
        cnt = map.size();

        int l = -1, r = -1;
        for (int i = 0, j = 0, c = 0; i < s.size(); i++) {
            map[s[i]]--;
            if (!map[s[i]]) c++;

            while (c == cnt && map[s[j]] < 0) {
                map[s[j]]++;
                j++;
            }

            if (c == cnt)
                if (l == -1 || r - l > i - j) 
                    l = j, r = i;
        }
        
        return ~l ? s.substr(l, r - l + 1) : "";
    }
};
// @lc code=end


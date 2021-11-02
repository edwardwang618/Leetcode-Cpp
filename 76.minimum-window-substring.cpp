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
        
        // mp是t的信息
        unordered_map<char, int> mp;
        for (char ch : t) mp[ch]++;
        int cnt = mp.size();

        int l = -1, r = -1;
        // 每次进循环，j是如果暂时没发现解的话，j=0；否则j就是上一个i对应的满足条件的最右左端点
        for (int i = 0, j = 0; i < s.size(); i++) {
            // 维护滑动窗口[j, i]的字母构成
            mp[s[i]]--;

            if (!mp[s[i]]) cnt--;

            while (!cnt && mp[s[j]] < 0) {
                mp[s[j]]++;
                j++;
            }

            if (!cnt && (l == -1 || i - j < r - l)) l = j, r = i;
        }

        return ~l ? s.substr(l, r - l + 1) : "";
    }
};
// @lc code=end


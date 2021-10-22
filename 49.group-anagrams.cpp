/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

// @lc code=start
class Solution {
public:
    using UL = unsigned long;
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<UL, vector<string>> mp;
        for (string s : strs) mp[getHash(s)].push_back(s);

        vector<vector<string>> res;
        for (auto &p : mp) res.push_back(p.second);
        return res;
    }

    UL getHash(string s) {
        vector<int> cnt(26, 0);
        for (char ch : s) cnt[ch - 'a']++;
        
        UL hash = 0;
        for (int x : cnt) hash = hash * 131L + x;
        return hash;
    }
};
// @lc code=end


/*
 * @lc app=leetcode id=30 lang=cpp
 *
 * [30] Substring with Concatenation of All Words
 */

// @lc code=start
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        int n = s.size();

        int m = words.size();
        // words里每个单词出现次数，key是单词的哈希，value就是这个key出现次数
        unordered_map<string, int> mp;
        for (int i = 0; i < m; i++) mp[words[i]]++;

        int k = words[0].size();
        for (int i = 0; i < n; i++) {
            if (i + k * m > n) break;
            unordered_map<string, int> used;
            bool flag = true;
            // j是在截取第几个单词
            for (int j = 0; j < m; j++) {
                int l = i + j * k, r = i + (j + 1) * k - 1;
                string sub = s.substr(l, r - l + 1);
                used[sub]++;
                if (used[sub] > mp[sub]) {
                    flag = false;
                    break;
                }
            }

            if (flag) res.push_back(i);
        }

        return res;
    }
};
// @lc code=end


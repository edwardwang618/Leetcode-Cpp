/*
 * @lc app=leetcode id=30 lang=cpp
 *
 * [30] Substring with Concatenation of All Words
 */

// @lc code=start
class Solution {
public:
    using UL = unsigned long;
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        int n = s.size();
        unsigned long P = 131L;
        auto hashS = vector<UL>(n + 1, 0), pow = vector<UL>(n + 1, 1);
        for (int i = 0; i < n; i++) {
            hashS[i + 1] = hashS[i] * P + s[i];
            pow[i + 1] = pow[i] * P;
        }

        int m = words.size();
        // words里每个单词出现次数，key是单词的哈希，value就是这个key出现次数
        unordered_map<UL, int> mp;
        for (int i = 0; i < m; i++) {
            UL hash = 0;
            for (char ch : words[i]) hash = hash * P + ch;
            mp[hash]++;
        }

        int k = words[0].size();
        for (int i = 0; i < n; i++) {
            if (i + k * m > n) break;
            unordered_map<UL, int> used;
            bool flag = true;
            // j是在截取第几个单词
            for (int j = 0; j < m; j++) {
                int l = i + j * k, r = i + (j + 1) * k - 1;
                UL hash = getHash(hashS, l, r, pow);
                used[hash]++;
                if (used[hash] > mp[hash]) {
                    flag = false;
                    break;
                }
            }

            if (flag) res.push_back(i);
        }

        return res;
    }

    unsigned long getHash(vector<UL> &hashS, int l, int r, vector<UL> &pow) {
        return hashS[r + 1] - hashS[l] * pow[r - l + 1];
    }
};
// @lc code=end


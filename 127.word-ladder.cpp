/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
 */

// @lc code=start
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> set;
        for (auto s : wordList) set.insert(s);
        if (!set.count(endWord)) return 0;

        queue<string> q;
        q.push(beginWord);
        unordered_set<string> vis;
        vis.insert(beginWord);

        int res = 0;
        while (q.size()) {
            res++;
            for (int i = q.size(); i; i--) {
                auto s = q.front(); q.pop();
                // 将哪个字母做变换
                for (int j = 0; j < s.size(); j++) {
                    auto old = s[j];
                    // 在枚举将这个字母变成谁
                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        if (ch == old) continue;
                        s[j] = ch;
                        if (set.count(s) && !vis.count(s)) {
                            if (s == endWord) return res + 1;
                            vis.insert(s);
                            q.push(s);
                        }
                    }

                    s[j] = old;
                }
            }
        }

        return 0;
    }
};
// @lc code=end


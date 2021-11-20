/*
 * @lc app=leetcode id=126 lang=cpp
 *
 * [126] Word Ladder II
 */

// @lc code=start
class Solution {
public:
    unordered_map<string, int> dist;
    unordered_set<string> set;
    queue<string> q;
    vector<vector<string>> res;
    vector<string> v;

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        for (auto s : wordList) set.insert(s);
        if (!set.count(endWord)) return {};
        
        dist[beginWord] = 0;
        q.push(beginWord);

        int step = 0;
        while (q.size()) {
            step++;
            for (int k = q.size(); k; k--) {
                auto s = q.front(); q.pop();
                for (int i = 0; i < s.size(); i++) {
                    char old = s[i];
                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        if (ch == old) continue;
                        s[i] = ch;
                        if (set.count(s) && !dist.count(s)) {
                            dist[s] = step;
                            if (s != endWord) q.push(s);
                        }
                    }

                    s[i] = old;
                }
            }
        }

        set.insert(beginWord);
        dfs(endWord);
        for (auto &l : res) reverse(l.begin(), l.end());
        return res;
    }

    void dfs(string s) {
        v.push_back(s);
        if (dist.count(s) && !dist[s]) {
            res.push_back(v);
            v.pop_back();
            return;
        }

        int d = dist[s];
        for (int i = 0; i < s.size(); i++) {
            char old = s[i];
            for (char ch = 'a'; ch <= 'z'; ch++) {
                if (ch == old) continue;
                s[i] = ch;
                if (dist.count(s) && dist[s] == d - 1) dfs(s);
            }
            s[i] = old;
        }

        v.pop_back();
    }
};
// @lc code=end


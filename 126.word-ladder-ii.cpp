/*
 * @lc app=leetcode id=126 lang=cpp
 *
 * [126] Word Ladder II
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        // 求最短路 + 建图 -> 从end -》 begin
        // DFS的时候，要从begin -》 end
        vector<vector<string>> res;
        unordered_set<string> set;
        for (auto s : wordList) set.insert(s);
        if (!set.count(endWord)) return res;

        unordered_map<string, vector<string>> g;
        // 0, [1, 2, 3]
        // 1, [2, 3]

        unordered_map<string, int> dist;
        dist[endWord] = 0;

        queue<string> q;
        q.push(endWord);
        while (q.size()) {
            auto s = q.front(); q.pop();
            auto t = s;
            for (int i = 0; i < s.size(); i++) {
                char old = s[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    if (ch == old) continue;

                    s[i] = ch;
                    if (s == beginWord || set.count(s))
                        if (!dist.count(s) || dist[s] == dist[t] + 1) {
                            g[s].push_back(t);
                            if (!dist.count(s)) q.push(s);

                            dist[s] = dist[t] + 1;
                            if (s == beginWord) break;
                        }
                }

                s[i] = old;
            }
        }

        if (!dist.count(beginWord)) return res;

        vector<string> v;
        dfs(beginWord, dist, v, res, g);
        return res;
    }

    void dfs(string s, unordered_map<string, int> &dist, vector<string> &v, vector<vector<string>> &res, unordered_map<string, vector<string>> &g) {
        v.push_back(s);
        if (!dist[s]) {
            res.push_back(v);
            v.pop_back();
            return;
        }

        for (auto ne : g[s]) dfs(ne, dist, v, res, g);
        v.pop_back();
    }
};
// @lc code=end


/*
 * @lc app=leetcode id=93 lang=cpp
 *
 * [93] Restore IP Addresses
 */

// @lc code=start
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        if (s.size() > 12) return res;

        string p;
        dfs(0, 0, p, res, s);
        return res;
    }

    void dfs(int u, int cnt, string &p, vector<string> &res, string &s) {
        if (u == s.size()) {
            if (cnt == 4) {
                p.pop_back();
                res.push_back(p);
                p += ".";
            }
            
            return;
        }

        for (int i = u; i <= u + 2 && i < s.size(); i++) {
            int x = stoi(s.substr(u, i - u + 1));
            if (x <= 255 && !(s[u] == '0' && i > u) && cnt + 1 <= 4) {
                p += s.substr(u, i - u + 1) + ".";
                dfs(i + 1, cnt + 1, p, res, s);
                p.resize(p.size() - (i - u + 1) - 1);
            }
        }
    }
};
// @lc code=end


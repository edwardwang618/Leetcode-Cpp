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
        dfs(0, 0, s, p, res);
        return res;
    }

    void dfs(int u, int cnt, string &s, string &p, vector<string> &res) {
        if (u == s.size() || cnt == 4) {
            if (u == s.size() && cnt == 4) {
                p.pop_back();
                res.push_back(p);
                p += ".";
            }

            return;
        }

        for (int i = u; i < min((int) s.size(), u + 3); i++) {
            string n = s.substr(u, i - u + 1);
            if (n.size() > 1 && n[0] == '0') break;

            int x = stoi(n);
            if (x <= 255) {
                p += n + ".";
                dfs(i + 1, cnt + 1, s, p, res);
                p.resize(p.size() - n.size() - 1);
            }
        }
    }
};
// @lc code=end


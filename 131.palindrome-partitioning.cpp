/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 */

// @lc code=start
class Solution {
public:
    using UL = unsigned long;
    vector<UL> hash_l, hash_r, pow;
    
    vector<vector<string>> partition(string s) {
        // 动规  f[i][j]是s[i:j]是否是回文串
        // f[i][j] = true, i == j
        //           s[i] == s[j]      i == j - 1
        //           s[i] == s[j] && f[i + 1][j - 1]      i < j - 1
        // 区间dp
        int n = s.size();
        UL P = 131L;
        hash_l = vector<UL>(n + 1, 0);
        hash_r = vector<UL>(n + 1, 0);
        pow = vector<UL>(n + 1, 1);
        
        for (int i = 0; i < n; i++) {
            hash_l[i + 1] = hash_l[i] * P + s[i];
            hash_r[n - i - 1] = hash_r[n - i] * P + s[n - i - 1];
            pow[i + 1] = pow[i] * P;
        }

        vector<vector<string>> res;
        vector<string> v;
        dfs(0, s, v, res);
        return res;
    }

    void dfs(int u, string &s, vector<string> &v, vector<vector<string>> &res) {
        if (u == s.size()) {
            res.push_back(v);
            return;
        }

        // 枚举当前截取的字符串的右端点
        for (int i = u; i < s.size(); i++) {
            if (check(u, i)) {
                v.push_back(s.substr(u, i - u + 1));
                dfs(i + 1, s, v, res);
                v.pop_back();
            }
        }
    }

    bool check(int l, int r) {
        int len = r - l + 1;
        if (len & 1) {
            // l ~ l + len / 2 = l + len / 2 ~ r
            return hash_left(l, l + len / 2) == hash_right(l + len / 2, r);
        } else {
            // l ~ l + len / 2 - 1 = l + len / 2 ~ r
            return hash_left(l, l + len / 2 - 1) == hash_right(l + len / 2, r);
        }
    }

    UL hash_left(int l, int r) {
        return hash_l[r + 1] - hash_l[l] * pow[r - l + 1];
    }

    UL hash_right(int l, int r) {
        return hash_r[l] - hash_r[r + 1] * pow[r - l + 1];
    }
};
// @lc code=end


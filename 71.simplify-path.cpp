/*
 * @lc app=leetcode id=71 lang=cpp
 *
 * [71] Simplify Path
 */

// @lc code=start
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> v;
        for (int i = 0; i < path.size(); i++) {
            if (path[i] == '/') continue;
            int j = i;
            while (j < path.size() && path[j] != '/') j++;
            v.push_back(path.substr(i, j - i));

            i = j - 1;
        }

        vector<string> stk;
        for (auto s : v) {
            if (s == ".") continue;
            else if (s == "..") {
                if (stk.size()) stk.pop_back();
            } else {
                stk.push_back(s);
            }
        }

        string res;
        if (stk.empty()) return "/";
        for (int i = 0; i < stk.size(); i++)
            res += "/" + stk[i];
        
        return res;
    }
};
// @lc code=end


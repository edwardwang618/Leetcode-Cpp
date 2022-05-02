/*
 * @lc app=leetcode id=135 lang=cpp
 *
 * [135] Candy
 */

// @lc code=start
class Solution {
public:
    int candy(vector<int>& a) {
        int n = a.size();
        vector<int> f(n, 1);
        for (int i = 0; i < n - 1; i++)
            if (a[i + 1] > a[i]) f[i + 1] = max(f[i + 1], f[i] + 1);
        
        for (int i = n - 1; i; i--)
            if (a[i - 1] > a[i]) f[i - 1] = max(f[i - 1], f[i] + 1);
        
        int res = 0;
        for (auto x : f) res += x;
        return res;
    }
};
// @lc code=end


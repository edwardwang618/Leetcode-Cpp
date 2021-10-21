/*
 * @lc app=leetcode id=60 lang=cpp
 *
 * [60] Permutation Sequence
 */

// @lc code=start
class Solution {
public:
    string getPermutation(int n, int k) {
        int fact[9];
        fact[0] = 1;
        for (int i = 1; i < 9; i++) fact[i] = i * fact[i - 1];

        vector<int> v;
        for (int i = 1; i <= n; i++) v.push_back(i);

        k--;
        string res;
        for (int i = n - 1; i >= 0; i--) {
            int s = k / fact[i];
            res += to_string(v[s]);
            v.erase(v.begin() + s);
            k -= s * fact[i];
        }

        return res;
    }
};
// @lc code=end


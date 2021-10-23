/*
 * @lc app=leetcode id=60 lang=cpp
 *
 * [60] Permutation Sequence
 */

// @lc code=start
class Solution {
public:
    string getPermutation(int n, int k) {
        // fact[i] = i!
        vector<int> fact(n, 0);
        fact[0] = 1;
        for (int i = 1; i < n; i++) fact[i] = i * fact[i - 1];

        k--;
        string res;
        // 需要一个数据结构，可以返回排名第k的数，并且可以删除某个元素；
        // balanced tree BBST, log n
        vector<int> v;
        for (int i = 1; i <= n; i++) v.push_back(i);

        for (int i = n - 1; i >= 0; i--) {
            int g = k / fact[i];
            res += to_string(v[g]);
            k -= g * fact[i];
            v.erase(v.begin() + g); // O(n)
        }

        return res;
    }

    // string getPermutation(int n, int k) {
    //     // fact[i] = i!
    //     vector<int> A;
    //     for (int i = 1; i <= n; i++) A.push_back(i);
    //     vector<bool> used(n, false);
    //     string s;
    //     dfs(0, A, used, k, s);
    //     return s;
    // }

    // bool dfs(int u, vector<int> &A, vector<bool> &used, int &k, string &s) {
    //     if (u == A.size()) {
    //         k--;
    //         return !k;
    //     }

    //     for (int i = 0; i < A.size(); i++) {
    //         if (used[i]) continue;

    //         s += '0' + A[i];
    //         used[i] = true;
    //         if (dfs(u + 1, A, used, k, s)) return true;
    //         used[i] = false;
    //         s.pop_back();
    //     }

    //     return false;
    // }
};
// @lc code=end


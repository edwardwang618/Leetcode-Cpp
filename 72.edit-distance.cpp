/*
 * @lc app=leetcode id=72 lang=cpp
 *
 * [72] Edit Distance
 */

// @lc code=start
class Solution {
public:
    int minDistance(string s, string t) {
        // 设f[i][j]从s的前i个字符到t的前j个字符至少多少个变换
        // f[0][j] = j
        // f[i][j] 
        // 如果s[i-1]和t[j-1]不等，第一种添加t[j-1]，至少要f[i][j - 1] + 1
        // 第二种是删除，至少要f[i - 1][j] + 1
        // 第三种是替换，至少要f[i - 1][j - 1] + 1

        // s[i - 1]和t[j-1]相等的情况，不动最后一个字符，至少f[i - 1][j - 1]
        int m = s.size(), n = t.size();
        int f[m + 1][n + 1];
        for (int i = 0; i <= m; i++)
            for (int j = 0; j <= n; j++)
                if (!i) f[i][j] = j;
                else if (!j) f[i][j] = i;
                else {
                    if (s[i - 1] == t[j - 1]) f[i][j] = f[i - 1][j - 1];
                    else f[i][j] = min(f[i][j - 1] + 1, min(f[i - 1][j] + 1, f[i - 1][j - 1] + 1));
                }
        
        return f[m][n];
    }
};
// @lc code=end


/*
 * @lc app=leetcode id=52 lang=cpp
 *
 * [52] N-Queens II
 */

// @lc code=start
class Solution {
public:
    // col[i]是第i列放没放过皇后
    vector<bool> col;
    // 左上到右下的对角线是diag，从右上到左下的对角线udiag
    // diag最右上是第0条对角线，以此类推，udiag最左上的是第0条对角线
    vector<bool> diag, udiag;
    
    int totalNQueens(int n) {
        int res = 0;
        col = vector<bool>(n, false);
        diag = vector<bool>(2 * n - 1, false);
        udiag = vector<bool>(2 * n - 1, false);

        // pos[i]意思是第i行皇后的下标
        vector<int> pos;
        dfs(0, pos, n, res);
        return res;
    }

    void dfs(int u, vector<int> &pos, int n, int &res) {
        if (u == n) {
            res++;
            return;
        }

        for (int i = 0; i < n; i++) {
            // 当前列或者当前对角线放过，所以当前位置不能放
            if (col[i] || diag[n - 1 + u - i] || udiag[u + i]) continue;

            col[i] = diag[n - 1 + u - i] = udiag[u + i] = true;
            pos.push_back(i);
            dfs(u + 1, pos, n, res);
            col[i] = diag[n - 1 + u - i] = udiag[u + i] = false;
            pos.pop_back();
        }
    }
};
// @lc code=end


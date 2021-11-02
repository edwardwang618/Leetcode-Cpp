/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start
class Solution {
public:
    int d[5] = {-1, 0, 1, 0, -1};

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (dfs(i, j, 0, vis, word, board)) return true;
        
        return false;
    }

    bool dfs(int x, int y, int u, vector<vector<bool>> &vis, string word, vector<vector<char>>& board) {
        if (board[x][y] != word[u]) return false;
        if (u == word.size() - 1) return true;

        vis[x][y] = true;
        for (int k = 0; k < 4; k++) {
            int nx = x + d[k], ny = y + d[k + 1];
            if (0 <= nx && nx < board.size() && 0 <= ny && ny < board[0].size() && !vis[nx][ny])
                if (dfs(nx, ny, u + 1, vis, word, board)) return true;
        }

        vis[x][y] = false;
        return false;
    }
};
// @lc code=end


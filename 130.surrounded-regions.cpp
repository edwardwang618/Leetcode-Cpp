/*
 * @lc app=leetcode id=130 lang=cpp
 *
 * [130] Surrounded Regions
 */

// @lc code=start
class Solution {
public:
    int d[5] = {-1, 0, 1, 0, -1};
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O') dfs(i, 0, board, 'O', '$');
            if (board[i][m - 1] == 'O') dfs(i, m - 1, board, 'O', '$');
        }
        for (int i = 0; i < m; i++) {
            if (board[0][i] == 'O') dfs(0, i, board, 'O', '$');
            if (board[n - 1][i] == 'O') dfs(n - 1, i, board, 'O', '$');
        }

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (board[i][j] == 'O') dfs(i, j, board, 'O', 'X');
        

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) 
                if (board[i][j] == '$') dfs(i, j, board, '$', 'O');
    }

    void dfs(int x, int y, vector<vector<char>> &board, char ol, char ne) {
        board[x][y] = ne;
        for (int i = 0; i < 4; i++) {
            int nx = x + d[i], ny = y + d[i + 1];
            if (0 <= nx && nx < board.size() && 0 <= ny && ny < board[0].size() && board[nx][ny] == ol)
                dfs(nx, ny, board, ol, ne);
        }
    }
};
// @lc code=end


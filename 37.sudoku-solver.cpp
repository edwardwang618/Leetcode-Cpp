/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 */

// @lc code=start
class Solution {
public:
    bool row[9][10], col[9][10], sq[9][10];
    
    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                if (board[i][j] != '.') {
                    int n = board[i][j] - '0';
                    row[i][n] = col[j][n] = sq[i / 3 * 3 + j / 3][n] = true;
                }

        dfs(0, 0, board);
    }

    bool dfs(int x, int y, vector<vector<char>>& board) {
        if (y == 9) return dfs(x + 1, 0, board);
        if (x == 9) return true;

        int i = x / 3, j = y / 3;
        if (board[x][y] != '.') {
            int n = board[x][y] - '0';
            row[x][n] = col[y][n] = sq[i * 3 + j][n] = true;
            return dfs(x, y + 1, board);
        } else {
            for (int k = 1; k <= 9; k++) {
                board[x][y] = '0' + k;
                if (row[x][k] || col[y][k] || sq[i * 3 + j][k]) continue;

                row[x][k] = col[y][k] = sq[i * 3 + j][k] = true;
                if (dfs(x, y + 1, board)) return true;
                row[x][k] = col[y][k] = sq[i * 3 + j][k] = false;
            }

            board[x][y] = '.';
            return false;
        }
    }
};
// @lc code=end


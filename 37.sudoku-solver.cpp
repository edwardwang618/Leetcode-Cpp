/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 */

// @lc code=start
class Solution {
public:
    // row[0][8] = true的意思是第0行8取过了
    bool row[9][10], col[9][10], sq[9][10];
    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int x = board[i][j] - '0';
                    // (i / 3, j / 3)是(i, j)所在3乘3中方格的坐标
                    row[i][x] = col[j][x] = sq[i / 3 * 3 + j / 3][x] = true;
                }
            }

        dfs(0, 0, board);
    }

    bool dfs(int x, int y, vector<vector<char>> &board) {
        if (x == 9) return true;
        if (y == 9) return dfs(x + 1, 0, board);
        
        if (board[x][y] != '.') return dfs(x, y + 1, board);
        for (int i = 1; i <= 9; i++) {
            if (row[x][i] || col[y][i] || sq[x / 3 * 3 + y / 3][i]) continue;
            row[x][i] = col[y][i] = sq[x / 3 * 3 + y / 3][i] = true;
            board[x][y] = '0' + i;
            if (dfs(x, y + 1, board)) return true;

            row[x][i] = col[y][i] = sq[x / 3 * 3 + y / 3][i] = false;
        }

        board[x][y] = '.';
        return false;
    }
};
// @lc code=end


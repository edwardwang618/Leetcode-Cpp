/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */

// @lc code=start
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& A) {
        bool v[10];
        memset(v, 0, sizeof v);
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (A[i][j] == '.') continue;
                if (v[A[i][j] - '0']) return false;
                else v[A[i][j] - '0'] = true;
            }
            
            memset(v, 0, sizeof v);
        }

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (A[j][i] == '.') continue;
                if (v[A[j][i] - '0']) return false;
                else v[A[j][i] - '0'] = true;
            }
            
            memset(v, 0, sizeof v);
        }

        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++) {
                int x = i * 3, y = j * 3;
                for (int k = 0; k < 3; k++)
                    for (int l = 0; l < 3; l++) {
                        if (A[x + k][y + l] == '.') continue;
                        if (v[A[x + k][y + l] - '0']) return false;
                        v[A[x + k][y + l] - '0'] = true;
                    }

                memset(v, 0, sizeof v);
            }

        return true;
    }
};
// @lc code=end


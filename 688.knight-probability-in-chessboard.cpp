/*
 * @lc app=leetcode id=688 lang=cpp
 *
 * [688] Knight Probability in Chessboard
 */

// @lc code=start
class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        // B是概率空间的划分
        // 全概率公式，P(A) = P(A|B1)P(B1) + P(A|B2)P(B2) +...
        // f[k][x][y] = sum f[k - 1][x + dx][y + dy] * 0.125
        double f[2][n][n];
        memset(f, 0, sizeof f);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) 
                f[0][i][j] = 1;
        
        int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
        int dy[] = {2, 1, -1, -2, -2, -1, 1, 2};
        for (int i = 1; i <= k; i++) {
            fill(&f[i & 1][0][0], &f[i & 1][0][0] + n * n, 0.0);
            for (int x = 0; x < n; x++)
                for (int y = 0; y < n; y++) {
                    for (int k = 0; k < 8; k++) {
                        int nx = x + dx[k], ny = y + dy[k];
                        if (0 <= nx && nx < n && 0 <= ny && ny < n)
                            f[i & 1][x][y] += f[i - 1 & 1][nx][ny];
                    }

                    f[i & 1][x][y] *= 0.125;
                }
        }

        return f[k & 1][row][column];
    }
};
// @lc code=end


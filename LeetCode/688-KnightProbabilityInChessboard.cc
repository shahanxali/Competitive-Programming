//Question: https://leetcode.com/problems/knight-probability-in-chessboard/description/
//Level: Medium

class Solution {
public:

    int directions[8][2] = {{-2, -1}, {-2, 1}, {2, -1}, {2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}};
    

    double recur(int n, int k, int row, int column, vector<vector<vector<double>>> dp){

        dp[0][row][column] = 1.0;

        for (int step = 1; step <= k; step++) {
            for (int nr = 0; nr < n; nr++) {
                for (int nl = 0; nl < n; nl++) {
                    for (auto& d : directions) {
                        int ni = nr + d[0];
                        int nj = nl + d[1];
                        if (ni >= 0 && ni < n && nj >= 0 && nj < n) {
                            dp[step][nr][nl] += dp[step - 1][ni][nj];
                        }
                    }
                }
            }
        }

        double count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                count += dp[k][i][j];
            }
        }

        return count;

    }

    double knightProbability(int n, int k, int row, int column) {

        vector<vector<vector<double>>> dp(k + 1, vector<vector<double>>(n, vector<double>(n, 0)));

        
        return recur(n, k, row, column, dp) / pow(8, k);

    }
};

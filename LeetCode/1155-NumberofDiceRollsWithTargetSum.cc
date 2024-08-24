//Question: https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/
//Level: Medium

class Solution {
public:
    int recur(int n, int k, int target, vector<vector<int>>& dp) {
        const int MOD = 1e9 + 7;

        // Fill dp array
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= target; ++j) {
                dp[i][j] = 0; // Initialize current cell
                for (int face = 1; face <= k; ++face) {
                    if (j - face >= 0) {
                        dp[i][j] = (dp[i][j] + dp[i - 1][j - face]) % MOD;
                    }
                }
            }
        }
        return dp[n][target];
    }

    int numRollsToTarget(int n, int k, int target) {
        const int MOD = 1e9 + 7;

        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        dp[0][0] = 1; // Base case: 1 way to reach target 0 with 0 dice

        return recur(n, k, target, dp);
    }
};

//Question: https://leetcode.com/problems/longest-common-subsequence/
//Level: Medium

class Solution {
public:
    int computeLCS(string& text1, string& text2, vector<vector<int>>& dp) {
        int n = text1.size();
        int m = text2.size();

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;  // Characters match
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);  // Characters don't match
                }
            }
        }

        // Return the length of LCS
        return dp[n][m];
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        // DP table initialized to 0 (size (n+1) x (m+1))
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Compute LCS
        return computeLCS(text1, text2, dp);
    }
};

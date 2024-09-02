//Question: https://leetcode.com/problems/unique-binary-search-trees/
//Level: Medium


//DP3

class Solution {
public:

    int recur(int n, vector<int> dp){

        dp[0] = 1;
        dp[1] = 1;

        for(int i = 2; i <= n; i++){

            int sum = 0;
            for(int j = 0; j <= i - 1; j++){
                sum += dp[j] * dp[i - j - 1];
            }
            dp[i] = sum;

        }


        return dp[n];

    }

    int numTrees(int n) {

        vector<int> dp(n + 1);
        
        return recur(n, dp);

    }
};






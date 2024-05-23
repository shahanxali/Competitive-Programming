//Question: https://leetcode.com/problems/triangle/description/
//Level: Medium

class Solution {
public:

    int helper(vector<vector<int>> arr){
        int dp[205][205];
        memset(dp,0,sizeof dp);
        

        for(int i=arr.size()-1; i>=0; i--){
            for(int j=arr[i].size()-1; j>=0; j--){
                int a = arr[i][j] + dp[i+1][j];
                int b = arr[i][j] + dp[i+1][j+1];

                dp[i][j] = min(a,b);
            }
        }
        return dp[0][0];
    }
    int minimumTotal(vector<vector<int>>& arr) {
        return helper(arr);
    }
};
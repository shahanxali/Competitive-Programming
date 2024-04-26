//Question: 
//Level: Medium

//DP

//first step recursive

class Solution {
public:

    int recur(int m, int n){

        if(m == 1 && n == 1){
            return 1;
        }

        int up = 0, down = 0;
        if(m > 1) up = recur(m - 1, n);
        if(n > 1) down = recur(m, n - 1);

        return up + down;

    }

    int uniquePaths(int m, int n) {
        
        if(m ==0 || n == 0){
            return 0;
        }

        return recur(m, n);

    }
};






//Second Step Top Down:

class Solution {
public:

    vector<vector<int>> dp;

    int recur(int m, int n){

        if(m == 1 && n == 1){
            return 1;
        }

        if(dp[m][n] != 0){
            return dp[m][n];
        }

        int up = 0, down = 0;
        
        if(m > 1) up = recur(m - 1, n);
        if(n > 1) down = recur(m, n - 1);

        return dp[m][n] = up + down;

    }

    int uniquePaths(int m, int n) {

        if(m ==0 || n == 0){
            return 0;
        }

        dp.assign(m + 1, vector<int> (n + 1, 0));

        return recur(m, n);

    }
};



//Bottom Up now:

class Solution {
public:

    vector<vector<int>> dp;

    int recur(int m, int n){

        dp[1][1] = 1;

        int up = 0, down = 0;

        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){

                if(i > 1)
                    dp[i][j] += dp[i - 1][j];

                if(j > 1)
                    dp[i][j] += dp[i][j - 1];
                
            }
        }

        return dp[m][n];

    }

    int uniquePaths(int m, int n) {

        if(m ==0 || n == 0){
            return 0;
        }

        dp.assign(m + 1, vector<int> (n + 1, 0));

        return recur(m, n);

    }
};






//Space optimization:









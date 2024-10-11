//Question: https://leetcode.com/problems/perfect-squares/?envType=problem-list-v2&envId=55ac4kuc
//Level: Medium

class Solution {
public:

    bool ispr(int n){
        int a = sqrt(n);
        return a * a == n;
    }

    int dp(int n, vector<int> memo){

        if(ispr(n)) return 1;
        memo[0] = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= sqrt(i); j++){

                int jsq = j * j;
                memo[i] = min(memo[i], memo[i - jsq] + 1);

            }
        }

        return memo[n];

    }

    int numSquares(int n) {

        vector<int> memo(n + 1, INT_MAX);

        return dp(n, memo);

    }
};

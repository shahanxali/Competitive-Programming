//Question: https://leetcode.com/problems/min-cost-climbing-stairs/
//Level: Easy

//THE QUESTION IS SOLVED WITH DYNAMIC PROGRAMMING

//Recursive:

class Solution {
public:

    

    int recur(vector<int> cost, int n){

        if(n == 0){
            return cost[0];
        }
        if(n == 1){
            return cost[1];
        }


        int a = recur(cost, n - 1) + (n == cost.size() ? 0 : cost[n]);
        int b = recur(cost, n - 2) + (n == cost.size() ? 0 : cost[n]);

        int mini = min(a, b);

        return mini;

    }

    int minCostClimbingStairs(vector<int>& cost) {
        
        return recur(cost, cost.size());


        
    }
};



//Top Down:

class Solution {
public:

    vector<int> dp;

    int recur(vector<int> cost, int n){

        if(n == 0){
            return cost[0];
        }
        if(n == 1){
            return cost[1];
        }

        if(dp[n] != 0){
            return dp[n];
        }

        int a = recur(cost, n - 1) + (n == cost.size() ? 0 : cost[n]);
        int b = recur(cost, n - 2) + (n == cost.size() ? 0 : cost[n]);

        return dp[n] = min(a, b);

    }

    int minCostClimbingStairs(vector<int>& cost) {
        
        dp.assign(cost.size() + 1, 0);
        return recur(cost, cost.size());


        
    }
};






//Bottom Up:

class Solution {
public:

    vector<int> dp;

    int recur(vector<int> cost, int n){

        if(n == 0){
            return cost[0];
        }
        if(n == 1){
            return min(cost[1], cost[0]);
        }

        
        dp[0] = cost[0];
        dp[1] = cost[1];

        for(int i = 2; i <= n; i++){

            dp[i] = min(dp[i - 1], dp[i - 2]) + (i == cost.size() ? 0 : cost[i]);

        }


        return dp[n];

    }

    int minCostClimbingStairs(vector<int>& cost) {
        
        dp.assign(cost.size() + 1, 0);
        return recur(cost, cost.size());


        
    }
};



//Space Optimized:

class Solution {
public:


    int recur(vector<int> cost, int n){

        if(n == 0){
            return cost[0];
        }
        if(n == 1){
            return min(cost[1], cost[0]);
        }

        
        int a = cost[0];
        int b = cost[1];
        int c;

        for(int i = 2; i <= n; i++){

            c = min(a, b) + (i == cost.size() ? 0 : cost[i]);
            a = b;
            b = c;

        }


        return c;

    }

    int minCostClimbingStairs(vector<int>& cost) {
        
        return recur(cost, cost.size());


        
    }
};
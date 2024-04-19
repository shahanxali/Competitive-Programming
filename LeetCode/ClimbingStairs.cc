//Question: https://leetcode.com/problems/climbing-stairs/
//Level: Easy

//DYNAMIC PROGRAMMING

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> dp;

    int recur(int n) {
        // Base cases
        if (n == 0 || n == 1) {
            return 1;
        }

        // Check if the value is already computed
        if (dp[n] != -1) {
            return dp[n];
        }

        // Compute and store the value for dp[n]
        dp[n] = recur(n - 1) + recur(n - 2);

        return dp[n];
    }

    int climbStairs(int n) {
        // Initialize dp array with -1
        dp.assign(n + 1, -1);

        return recur(n);
    }
};

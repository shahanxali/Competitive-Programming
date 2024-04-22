//Question: https://leetcode.com/problems/minimum-path-sum/
//Level: Medium

//DYNAMIC PROGRAMMING



//Recursive Solution:

class Solution {
public:

    int recur(vector<vector<int>>& grid, int x, int y){

        if(x == 0 && y == 0){
            return grid[0][0];
        }
        
        int a = INT_MAX;
        int b = INT_MAX;

        if(x > 0) {
            a = recur(grid, x - 1, y) + grid[x][y];
        }
        if(y > 0) {
            b = recur(grid, x, y - 1) + grid[x][y];
        }

        return min(a, b);
    }

    int minPathSum(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        return recur(grid, grid.size() - 1, grid[0].size() - 1);
    }
};



//Top Down (Memoization): 

class Solution {
public:

    vector<vector<int>> dp;

    int recur(vector<vector<int>>& grid, int x, int y){

        if(x == 0 && y == 0){
            return grid[0][0];
        }
        
        if(dp[x][y] != 0){
            return dp[x][y];
        }

        int a = INT_MAX;
        int b = INT_MAX;

        if(x > 0) {
            a = recur(grid, x - 1, y) + grid[x][y];
        }
        if(y > 0) {
            b = recur(grid, x, y - 1) + grid[x][y];
        }

        return dp[x][y] = min(a, b);

    }

    int minPathSum(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;

        dp.assign(grid.size(), vector<int>(grid[0].size(), 0));


        return recur(grid, grid.size() - 1, grid[0].size() - 1);
    }
};





//Bottom Up (Tabulation):


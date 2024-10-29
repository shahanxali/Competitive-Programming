//Question: https://leetcode.com/problems/maximum-number-of-moves-in-a-grid/?envType=daily-question&envId=2024-10-29
//Level: Medium

class Solution {
public:
    int dp(vector<vector<int>>& grid, int row, int col, int count, vector<vector<int>>& memo) {

        if (col >= grid[0].size() - 1) return count;

        // Check if this subproblem has already been solved.
        if (memo[row][col] != -1) {
            return memo[row][col];
        }

        int maxMoves = count;

        // Move to the top-right cell if possible
        if (row > 0 && grid[row - 1][col + 1] > grid[row][col]) {
            maxMoves = max(maxMoves, dp(grid, row - 1, col + 1, count + 1, memo));
        }

        // Move to the right cell if possible
        if (grid[row][col + 1] > grid[row][col]) {
            maxMoves = max(maxMoves, dp(grid, row, col + 1, count + 1, memo));
        }

        // Move to the bottom-right cell if possible
        if (row < grid.size() - 1 && grid[row + 1][col + 1] > grid[row][col]) {
            maxMoves = max(maxMoves, dp(grid, row + 1, col + 1, count + 1, memo));
        }


        return memo[row][col] = maxMoves;


    }

    int maxMoves(vector<vector<int>>& grid) {

        int ans = 0;
        vector<vector<int>> memo(grid.size(), vector<int>(grid[0].size(), -1));

        for (int i = 0; i < grid.size(); i++) {
            ans = max(ans, dp(grid, i, 0, 0, memo));
        }

        return ans;


    }
};

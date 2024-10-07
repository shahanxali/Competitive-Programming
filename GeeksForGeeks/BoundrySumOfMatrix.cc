//Question: https://practice.geeksforgeeks.org/contest/gfg-weekly-175-rated-contest-1447/problems
//Level:

class Solution {
  public:

    int calculatesum(vector<vector<int>>& matrix, int level) {
        int count = 0;
        int n = matrix.size();

        // Top row (from left to right)
        for (int i = level; i < n - level; i++) {
            count += matrix[level][i];
        }

        // Right column (from top to bottom)
        for (int i = level + 1; i < n - level; i++) {
            count += matrix[i][n - level - 1];
        }

        // Bottom row (from right to left)
        for (int i = n - level - 2; i >= level; i--) {
            count += matrix[n - level - 1][i];
        }

        // Left column (from bottom to top)
        for (int i = n - level - 2; i > level; i--) {
            count += matrix[i][level];
        }

        return count;
    }

    vector<int> boundarySum(int n, vector<vector<int>>& matrix) {
        vector<int> ans;

        for (int i = 0; i < (n + 1) / 2; i++) {
            ans.push_back(calculatesum(matrix, i));
        }

        return ans;
    }
};

//Question: https://leetcode.com/problems/set-matrix-zeroes/?envType=daily-question&envId=2025-05-21
//Level: Medium

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        bool firstRow = false, firstCol = false;

        // Check if first row has zero
        for(int j = 0; j < n; j++) {
            if(matrix[0][j] == 0) firstRow = true;
        }

        // Check if first column has zero
        for(int i = 0; i < m; i++) {
            if(matrix[i][0] == 0) firstCol = true;
        }

        // Use first row and column as markers
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Set matrix[i][j] to 0 based on markers
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Update first row if needed
        if(firstRow) {
            for(int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }

        // Update first column if needed
        if(firstCol) {
            for(int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }

        return;

    }
};

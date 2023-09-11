//Question: https://leetcode.com/problems/n-queens/
//Level: Hard

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> solutions;
        vector<string> board(n, string(n, '.')); // Initialize an empty board
        
        solveNQueensRecursive(board, 0, solutions);
        
        return solutions;
    }
    
    void solveNQueensRecursive(vector<string>& board, int row, vector<vector<string>>& solutions) {
        if (row == board.size()) {
            solutions.push_back(board); // Found a valid solution
            return;
        }
        
        for (int col = 0; col < board.size(); col++) {
            if (isValidPlacement(board, row, col)) {
                board[row][col] = 'Q'; // Place a queen
                
                // Recursively try to place queens in the next row
                solveNQueensRecursive(board, row + 1, solutions);
                
                board[row][col] = '.'; // Backtrack by removing the queen
            }
        }
    }
    
    bool isValidPlacement(const vector<string>& board, int row, int col) {
        // Check the column
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }
        
        // Check the left diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        
        // Check the right diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < board.size(); i--, j++) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        
        return true;
    }
};

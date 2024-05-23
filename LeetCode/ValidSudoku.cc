//Question: https://leetcode.com/problems/valid-sudoku/
//Level: Medium

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Check for duplicates in rows, columns, and subgrids simultaneously
        unordered_set<string> seen;

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {

                char current = board[i][j];
                if (current != '.') {

                    // Check for duplicate in the same row, column, or subgrid
                    string row = "r" + to_string(i) + current;
                    string col = "c" + to_string(j) + current;
                    string subgrid = "s" + to_string(i / 3) + to_string(j / 3) + current;

                    if (seen.count(row) || seen.count(col) || seen.count(subgrid)) {
                        return false; // Duplicate found
                    }
                    else {
                        seen.insert(row);
                        seen.insert(col);
                        seen.insert(subgrid);
                    }

                }

            }
        }

        return true; // No duplicate digits found
    }
};


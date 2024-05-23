//Question: https://leetcode.com/problems/search-a-2d-matrix/
//Level: Medium



//Solution: 1 (Iterative, not good)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        bool ans = false;
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[i].size(); j++){

                if(matrix[i][j] == target){
                    ans = true;
                    break;
                }

            }
        }
        return ans;

    }
};






//SOlution: 2 (Binary search (recursion))

class Solution {
public:

    bool search(vector<vector<int>> matrix, int target, int m, int n, int start, int end){

        if(start > end){
            return false;
        }

        int mid = (start + end) / 2;
        int i = mid / n;
        int j = mid - (n * i);

        if(matrix[i][j] == target){
            return true;
        }

        if(matrix[i][j] > target){
            return search(matrix, target, m, n, start, mid - 1);
        }
        else{
            return search(matrix, target, m, n, mid + 1, end);
        }


    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        if(matrix.empty()) return false;

        int m = matrix.size();
        int n = matrix[0].size();

        //m * n - 2 gives the last element's pos if it were in 1d array
        return search(matrix, target, m, n, 0, (m * n) - 1);


    }
};





//Solution: 3 (Binary search iterative)

class Solution {
public:

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()) return false;

        int m = matrix.size();
        int n = matrix[0].size();
        
        int start = 0;
        int end = m * n - 1;
        int mid = (start + end) / 2;

        while(start <= end){

            int i = mid / n;
            int j = mid % n;
            int t = matrix[i][j];

            if(t == target){
                return true;
            }

            if(t > target){
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }

            mid = (start + end) / 2;
        }

        return false;
    }
};

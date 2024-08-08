//Question: https://leetcode.com/problems/spiral-matrix-iii/
//Level: Medium

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        
        int right = 1, down = 1, left = 2, up = 2;
        
        vector<vector<int>> ans;
        ans.push_back({rStart, cStart});

        int count = 1;
        int currrow = rStart, currcol = cStart;
        while(count < rows * cols){
            
            for(int i = 0; i < right; i++){
                currcol++;
                if(currcol >= 0 && currcol < cols && currrow >= 0 && currrow < rows){
                    ans.push_back({currrow, currcol});
                    count++;
                }
            }
            right += 2;

            for(int i = 0; i < down; i++){
                currrow++;
                if(currcol >= 0 && currcol < cols && currrow >= 0 && currrow < rows){
                    ans.push_back({currrow, currcol});
                    count++;
                }
            }
            down += 2;

            for(int i = 0; i < left; i++){
                currcol--;
                if(currcol >= 0 && currcol < cols && currrow >= 0 && currrow < rows){
                    ans.push_back({currrow, currcol});
                    count++;
                }
            }
            left += 2;

            for(int i = 0; i < up; i++){
                currrow--;
                if(currcol >= 0 && currcol < cols && currrow >= 0 && currrow < rows){
                    ans.push_back({currrow, currcol});
                    count++;
                }

            }
            up += 2;

        }

        return ans;

    }
};

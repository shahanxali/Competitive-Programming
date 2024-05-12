//Question: https://leetcode.com/contest/biweekly-contest-130/problems/check-if-grid-satisfies-conditions/
//Level: Easy

class Solution {
public:
    bool satisfiesConditions(vector<vector<int>>& grid) {
        
        bool ans = true;
        
        if(grid.size() == 1 && grid[0].size() == 1){
            return true;
        }
        
        
        if(grid.size() > 1){
            for(int i = 0; i < grid[0].size(); i++){
                for(int j = 0; j < grid.size() - 1; j++){

                    if(grid[j][i] != grid[j + 1][i]){
                        ans = false;
                    }

                }
                if(ans == false){
                    return false;
                }
            }
        }
        
        if(grid[0].size() > 1){
            for(int i = 0; i < grid.size(); i++){
                for(int j = 0; j < grid[0].size() - 1; j++){

                    if(grid[i][j] == grid[i][j + 1]){
                        ans = false;
                    }

                }
                if(ans == false){
                    return false;
                }
            }
        }
        
        
        return true;
        
        
    }
};
//Question: https://leetcode.com/problems/score-after-flipping-matrix/?envType=daily-question&envId=2024-05-13
//Level: Medium

class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        
        for(int i = 0; i < grid.size(); i++){

            if(grid[i][0] == 0){

                for(int j = 0; j < grid[i].size(); j++){
                    grid[i][j] = (grid[i][j]==1) ? 0 : 1;
                }

            }

        }

        for(int i = 0; i < grid[0].size(); i++){

            int count0 = 0;
            int count1 = 0;

            for(int j = 0; j < grid.size(); j++){

                grid[j][i] == 1 ? count1++ : count0++; 


            }

            if(count1 < count0){
                for(int j = 0; j < grid.size(); j++){ 

                    grid[j][i] = (grid[j][i]==1) ? 0 : 1;

                }
            }
        }

        int sum = 0;

        for(int i = 0; i < grid.size(); i++){

            int countpow = grid[i].size() - 1;
            int sumpow = 0;
            for(int j = 0; j < grid[i].size(); j++){

                sumpow += ((1 << countpow) * grid[i][j]);
                countpow--;

            }
            sum += sumpow;

        }

        return sum;


    }
};
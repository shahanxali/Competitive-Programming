//Question: https://leetcode.com/problems/lucky-numbers-in-a-matrix/?envType=daily-question&envId=2024-07-19
//Level: Easy

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        
        vector<int> ans;

        for(int i = 0; i < matrix.size(); i++){

            int mini = 0;
            for(int j = 0; j < matrix[i].size(); j++){
                mini = (min(matrix[i][mini], matrix[i][j]) == matrix[i][j]) ? j : mini;    
            }

            int maxi = 0;
            for(int j = 0; j < matrix.size(); j++){
                maxi = max(matrix[maxi][mini], matrix[j][mini]) == matrix[j][mini] ? j : maxi;
            }

            if(matrix[i][mini] == matrix[maxi][mini]){
                ans.push_back(matrix[i][mini]);
            }

        }

        return ans;

    }
};

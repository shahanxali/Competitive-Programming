//Question: https://leetcode.com/problems/convert-1d-array-into-2d-array/description/?envType=daily-question&envId=2024-09-01
//Level: Easy

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        
        if(m * n != original.size()){
            return {};
        }

        vector<vector<int>> ans(m, vector<int>(n));
        int f = m, e = n;

        for(int i = 0; i < original.size(); i++){

            ans[i / n][i % n] = original[i];

        }

        return ans;

    }
};

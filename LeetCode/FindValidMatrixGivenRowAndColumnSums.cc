//Question: https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums/description/
//Level: Medium

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        
        vector<vector<int>> ans(rowSum.size(), vector<int> (colSum.size(), 0));
        vector<int> carried(colSum.size() + rowSum.size(), 0);

        for(int i = 0; i < rowSum.size(); i++){

            for(int j = 0; j < colSum.size(); j++){

                if(rowSum[i] != 0){
                    if(colSum[j] > rowSum[i]){
                        ans[i][j] += rowSum[i];
                        colSum[j] -= rowSum[i];
                        rowSum[i] = 0;
                    }
                    else{
                        ans[i][j] += colSum[j];
                        rowSum[i] -= colSum[j];                        
                        colSum[j] = 0;
                    }
                }


            }


        }

        return ans;

    }
};

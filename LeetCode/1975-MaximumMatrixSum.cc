//Question: https://leetcode.com/problems/maximum-matrix-sum/?envType=daily-question&envId=2024-11-24
//Level: Medium

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {

        long long count = 0;
        int neg = INT_MAX, odev = 0;

        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                int temp = matrix[i][j];

                if(temp < 0) odev++;
                count += abs(temp);
                neg = min(neg, abs(temp));
            }
        }

        if(odev % 2 == 0) return count;

        return  count -= 2 * neg;

    }
};

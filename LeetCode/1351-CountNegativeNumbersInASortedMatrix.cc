//Question: https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/description/?envType=daily-question&envId=2025-12-28
// Level: Easy

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {

        int count = 0;

        for(vector<int> row : grid) for(int ind : row) if(ind < 0) count++;

        return count;

    }
};

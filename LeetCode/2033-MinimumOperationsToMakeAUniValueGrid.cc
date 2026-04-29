//Question: https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/description/?envType=daily-question&envId=2026-04-28
//Level: Medium

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {

        vector<int> nums;

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                nums.push_back(grid[i][j]);
            }
        }

        sort(nums.begin(), nums.end());

        int med = nums[nums.size() / 2];
        int ans = 0;

        for(int i = 0; i < nums.size(); i++){
            int dif = abs(nums[i] - med);
            if(dif % x != 0) return -1;
            ans = ans + (dif / x);
        }

        return ans;

    }
};

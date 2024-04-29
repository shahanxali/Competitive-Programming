//Question: https://leetcode.com/problems/burst-balloons/description/
//Level: Hard

//DP - 3

//Recursive Solution


class Solution {
public:

    int recur(vector<int>& nums, int i, int j){
        if(i > j){
            return 0;
        }

        int ans = 0;

        for(int k = i; k <= j; k++){
            int left = (i == 0) ? 1 : nums[i - 1];
            int right = (j == nums.size() - 1) ? 1 : nums[j + 1];
            int val = left * nums[k] * right;

            ans = max(ans, val + recur(nums, i, k - 1) + recur(nums, k + 1, j));
        }

        return ans;
    }

    int maxCoins(vector<int>& nums) {
        return recur(nums, 0, nums.size() - 1);
    }
};







//Question: https://leetcode.com/problems/longest-strictly-increasing-or-strictly-decreasing-subarray/?envType=daily-question&envId=2025-02-03
//Level: Easy

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {

        //Increasing

        int temp = 1, ans = 1;

        for(int i = 0; i < nums.size() - 1; i++){
            int a = nums[i], b = nums[i + 1];

            if(a < b) temp++;
            else{
                temp = 1;
            }
            ans = max(ans, temp);
        }

        //Decreasing
        temp = 1;
        for(int i = 0; i < nums.size() - 1; i++){
            int a = nums[i], b = nums[i + 1];

            if(a > b) temp++;
            else{
                temp = 1;
            }
            ans = max(ans, temp);
        }

        return ans;

    }
};

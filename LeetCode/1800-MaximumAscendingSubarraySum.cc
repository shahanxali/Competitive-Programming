//Question: https://leetcode.com/problems/maximum-ascending-subarray-sum/?envType=daily-question&envId=2025-02-04
//Level: Easy

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {

        if(nums.size() == 1) return nums[0];

        int ans = 0, temp = nums[0];

        for(int i = 0; i < nums.size() - 1; i++){

            ans = max(ans, temp);
            int a = nums[i], b = nums[i + 1];
            if(a < b) temp += b;
            else temp = b;
            ans = max(ans, temp);

        }

        return ans;

    }
};

//Question: https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores/?envType=daily-question&envId=2026-01-25
//Level: Easy

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {

        sort(nums.begin(), nums.end());

        int ans = INT_MAX;
        for(int i = 0; i <= nums.size() - k; i++){
            ans = min(ans, nums[i + k - 1] - nums[i]);
        }

        return ans;

    }
};

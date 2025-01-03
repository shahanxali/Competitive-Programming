//Question: https://leetcode.com/problems/number-of-ways-to-split-array/?envType=daily-question&envId=2025-01-03
//Level: Medium

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {

        long long last = 0, cum = 0;
        int ans = 0;

        for(auto num : nums) last += num;

        for(int i = 0; i < nums.size() - 1; i++){
            cum += nums[i];
            ans += cum >= last - cum;
        }

        return ans;

    }
};

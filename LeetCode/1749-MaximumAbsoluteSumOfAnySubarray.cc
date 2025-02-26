//Question: https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/?envType=daily-question&envId=2025-02-26
//Level: Medium

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {

        int temp1 = 0, temp2 = 0, ans1 = 0, ans2 = 0;

        for(int i = 0; i < nums.size(); i++){

            temp2 = min(temp2 + nums[i], nums[i]);
            ans2 = min(ans2, temp2);

            temp1 = max(temp1 + nums[i], nums[i]);
            ans1 = max(ans1, temp1);

        }

        return max(abs(ans1), abs(ans2));

    }
};

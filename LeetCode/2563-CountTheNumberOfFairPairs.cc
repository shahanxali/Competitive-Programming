//Question: https://leetcode.com/problems/count-the-number-of-fair-pairs/?envType=daily-question&envId=2024-11-13
//Level: Medium

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {

        long long count = 0;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size() - 1; i++){

            auto a = upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]);
            auto b = lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]);

            count += (a - b);
        }

        return count;

    }
};

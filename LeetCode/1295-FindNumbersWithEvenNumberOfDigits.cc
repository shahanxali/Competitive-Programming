//Question: https://leetcode.com/problems/find-numbers-with-even-number-of-digits/description/?envType=daily-question&envId=2025-04-30
//Level: Easy

class Solution {
public:
    int findNumbers(vector<int>& nums) {

        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            int n = ceil(log(nums[i]));
            ans = n % 2 == 0 ? ans + 1 : ans;
        }

        return ans;

    }
};

//Question: https://leetcode.com/problems/special-array-i/?envType=daily-question&envId=2025-02-01
//Level: Easy

class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {

        if(nums.size() == 0) return true;

        for(int i = 0; i < nums.size() - 1; i++){
            int a = nums[i], b = nums[i + 1];

            if((a % 2 == 0 && b % 2 == 0) || (a % 2 != 0 && b % 2 != 0)) return false;
        }

        return true;

    }
};

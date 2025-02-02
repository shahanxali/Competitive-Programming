//Question: https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/?envType=daily-question&envId=2025-02-02
//Level: Easy

class Solution {
public:
    bool check(vector<int>& nums) {

        int p = 0;
        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[p] > nums[p + 1]) break;
            p++;
        }
        if(p == nums.size() - 1) return true;
        p++;
        for(int i = p; i < nums.size() - 1; i++){
            if(nums[i] > nums[i + 1]) return false;
        }


        if(nums[0] < nums[nums.size() - 1]) return false;
        return true;


    }
};

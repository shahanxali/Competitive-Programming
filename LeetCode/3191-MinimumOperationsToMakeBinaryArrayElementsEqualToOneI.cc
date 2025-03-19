//Question: https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-i/?envType=daily-question&envId=2025-03-19
//Level: Medium

class Solution {
public:

    void change(vector<int>& nums, int i){
        nums[i] = nums[i] == 1 ? 0 : 1;
        return;
    }

    int minOperations(vector<int>& nums) {

        int first = 0, second = 2, ans = 0;

        while(second < nums.size()){
            if(nums[first] == 0){
                change(nums, first);
                change(nums, first + 1);
                change(nums, first + 2);
                ans++;
            }
            first++;
            second++;
        }
        second--;
        if(nums[second] == 0 || nums[second - 1] == 0) return -1;
        return ans;

    }
};

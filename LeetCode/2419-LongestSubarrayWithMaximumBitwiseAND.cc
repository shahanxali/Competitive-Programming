//Question: https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and/?envType=daily-question&envId=2024-09-14
//Level: Medium

class Solution {
public:
    int longestSubarray(vector<int>& nums) {

        int a = 0, count = 0;
        int maxel = *max_element(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); i++){

            if(!(nums[i] == maxel)){
                count = 0;
            }
            else{
                count++;
            }
            a = max(a, count);

        }

        return a;

    }
};

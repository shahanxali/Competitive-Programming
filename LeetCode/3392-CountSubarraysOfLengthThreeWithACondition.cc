//Question: https://leetcode.com/problems/count-subarrays-of-length-three-with-a-condition/submissions/1619690677/?envType=daily-question&envId=2025-04-27
//Level: Easy

class Solution {
public:
    int countSubarrays(vector<int>& nums) {

        int first = 0, third = 2, second = 1, count = 0;

        while(third < nums.size()){

            if((float)(nums[first] + nums[third]) == ((float)nums[second] / 2)) count++;

            first++;
            second++;
            third++;

        }

        return count;

    }
};

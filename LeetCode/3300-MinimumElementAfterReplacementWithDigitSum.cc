//Question: https://leetcode.com/problems/minimum-element-after-replacement-with-digit-sum/description/
//Level: Easy

class Solution {
public:
    int minElement(vector<int>& nums) {

        int mini = INT_MAX;
        for(int i = 0; i < nums.size(); i++){

            int temp = nums[i];
            int count = 0;

            while(temp != 0){
                count += temp % 10;
                temp /= 10;

            }
            mini = min(mini, count);
        }


        return mini;

    }
};

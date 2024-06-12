//Question: https://leetcode.com/problems/sort-colors/?envType=daily-question&envId=2024-06-12
//Level: Medium


class Solution {
public:
    void sortColors(vector<int>& nums) {

        for(int i = 0; i < nums.size(); i++){

            for(int j = 0; j < nums.size() - i - 1; j++){

                if(nums[j] > nums[j + 1]){
                    swap(nums[j], nums[j + 1]);
                }

            }

        }

    
    }
};

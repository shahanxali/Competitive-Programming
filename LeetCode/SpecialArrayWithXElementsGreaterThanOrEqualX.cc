//Question: https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/?envType=daily-question&envId=2024-05-27
//Level: Easy


//Recursive: (not that good)

class Solution {
public:
    int specialArray(vector<int>& nums) {
        
        int count = 1;
        sort(nums.begin(), nums.end(), [](const int& a, const int& b){return a < b;});

        if(nums.size() <= nums[0]){
            return nums.size();
        }

        for(int i = 1; i < nums.size(); i++){

            int s = nums.size() - count;
            if((s <= nums[i]) && (s > nums[i - 1])){
                return s;
            }
            count++;

        }
        return -1;
        
    }
};

//Next Solution: 

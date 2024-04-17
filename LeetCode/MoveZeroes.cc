//Question: https://leetcode.com/problems/move-zeroes/
//Level: Easy

//Solution - 1 (20% beat lol)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0; i < n; i++){

            if(nums[i] == 0){
                nums.push_back(0);
                nums.erase(nums.begin() + i);
                n--;
                i--;
            }
        }
    
    }
};


//Solution- 2 (very good)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
         
         int left=0;
        
         for(int i=0;i<nums.size();i++)
         {
            if(nums[i]!=0)
            {
                swap(nums[i],nums[left]);
                left++;
            }
         }
    }
};
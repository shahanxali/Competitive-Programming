//Question: https://leetcode.com/contest/biweekly-contest-113/problems/minimum-right-shifts-to-sort-the-array/
//Level: Easy

class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
        
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]<=nums[i+1]){
                if(i==nums.size()-2){
                    return 0;
                }
            }
            
            else{
                for(int j=i+1;j<nums.size()-1;j++){
                    
                    if(nums[j]>nums[j+1]){
                        return -1;
                    }
                    
                    if(j==nums.size()-2){
                        if(nums[nums.size()-1]<=nums[0]){
                            return nums.size()-i-1;
                        }
                        else{
                            return -1;
                        }
                    }
                    
                }
            }
            
            
        
        }
        return 0;
        
    }
};
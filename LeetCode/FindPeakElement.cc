//Question: https://leetcode.com/problems/find-peak-element/
//Level: Medium

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        

        int start = 0, end = nums.size() - 1;

        if(end == 0){
            return 0;
        }
        else if(end == 1){
            return nums[0] < nums[1] ? 1 : 0;
        }

        while(start < end){
            int mid = (start + end) / 2;

            if(nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]){
                return mid;
            }

            else if(nums[mid] < nums[mid - 1]){
                end = mid;
            }
            else if(nums[mid] < nums[mid + 1]){
                start = mid;
            }

            if(nums[start] > nums[start + 1]){
                return start;
            }
            else if(nums[end] > nums[end - 1]){
                return end;
            }


        }   
        return -1;
    }
};  
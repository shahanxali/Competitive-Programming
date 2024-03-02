//Question: https://leetcode.com/problems/search-insert-position/
//Level: Easy

class Solution {
public:

    int searchrecur(vector<int>& nums, int target, int start, int end){

        int pos = (start + end) / 2;
        if(nums[pos] == target){
            return pos;
        }
        else if(start + 1 == end){
            return end;
        }

        if(nums[pos] > target){
            return searchrecur(nums, target, start, pos - 1);
        }
        else {
            return searchrecur(nums, target, pos + 1, end);
        }
        

    }

    int searchInsert(vector<int>& nums, int target) {

        int pos = searchrecur(nums, target, 0, nums.size());
        return pos;  

    }
};
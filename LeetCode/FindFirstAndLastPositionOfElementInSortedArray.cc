//Question: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
//Level: Medium

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1;
        vector<int> ans = {-1, -1};

        if(nums.size() == 0){
            return ans;
        }

        while (start < end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] < target) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }

        if (nums[start] != target) {
            return ans;
        } else {
            
            ans[0] = start; 
        }

        end = nums.size() - 1;
        while (start < end) {
            int mid = start + (end - start + 1) / 2;
            if (nums[mid] > target) {
                end = mid - 1;
            } else {
                start = mid;
            }
        }

        ans[1] = start;

        return ans;
    }
};

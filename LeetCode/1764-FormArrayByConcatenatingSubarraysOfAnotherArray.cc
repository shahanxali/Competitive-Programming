//Question: https://leetcode.com/problems/form-array-by-concatenating-subarrays-of-another-array/
//Level: Medium

class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums){

        int groupIndex = 0;
        int elemIndex = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++){

            if (nums[i] == groups[groupIndex][elemIndex]){
                elemIndex++;

                if (elemIndex == groups[groupIndex].size()) {
                    groupIndex++;
                    elemIndex = 0;

                    if (groupIndex == groups.size()) return true;
                }
            }

            else if(elemIndex > 0) {
                i -= elemIndex;
                elemIndex = 0;
            }
        }

        return false;

    }
};

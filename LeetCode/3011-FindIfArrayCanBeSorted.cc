//Question: https://leetcode.com/problems/find-if-array-can-be-sorted/?envType=daily-question&envId=2024-11-06
//Level: Medium

class Solution {
public:

    int findbits(int n){
        return bitset<32>(n).count();
    }

    bool canSortArray(vector<int>& nums) {

        for(int i = 0 ; i < nums.size() - 1; i++){
            if(nums[i] > nums[i + 1]){
                if(findbits(nums[i]) == findbits(nums[i + 1])) swap(nums[i], nums[i + 1]);
                else return false;
            }
        }

        for(int i = nums.size() - 1 ; i >= 1; i--){
            if(nums[i] < nums[i - 1]){
                if(findbits(nums[i]) == findbits(nums[i - 1])) swap(nums[i], nums[i - 1]);
                else return false;
            }
        }

        return true;

    }
};

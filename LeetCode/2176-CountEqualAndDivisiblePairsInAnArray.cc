//Question: https://leetcode.com/problems/count-equal-and-divisible-pairs-in-an-array/?envType=daily-question&envId=2025-04-17

class Solution {
public:
    int countPairs(vector<int>& nums, int k) {

        int count = 0;
        for(int i = 0; i < nums.size() - 1; i++){
            for(int j = i + 1; j < nums.size(); j++){
                if(nums[i] == nums[j]){
                    count += ((i * j) % k == 0) ? 1 : 0;
                }
            }
        }


        return count;

    }
};

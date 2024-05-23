//Question: https://leetcode.com/problems/sum-of-all-subset-xor-totals/description/?envType=daily-question&envId=2024-05-20
//Level: Easy

class Solution {
public:


    int generateSubsets(int index, vector<int> nums, int nowxor){

    if (index == nums.size()) {
        return nowxor;
    }
    
    int a = generateSubsets(index + 1, nums, nowxor ^ nums[index]);

    int b = generateSubsets(index + 1, nums, nowxor);

    return a + b;

}

    int subsetXORSum(vector<int>& nums) {

        if(nums.size() == 0){
            return 0;
        }


        return generateSubsets(0, nums, 0);




    }
};
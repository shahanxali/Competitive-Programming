//Question: https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/description/?envType=daily-question&envId=2024-08-02
//Level: Medium

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i]){
                count++;
            }
        }

        if(count == 0 || count == nums.size()){
            return 0;
        }

        int countone = 0;
        int first = 0, second = count;

        for(int i = 0; i < second; i++){
            if(nums[i]){
                countone++;
            }

        }

        int right = false;
        int a = countone;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i % nums.size()] ){
                a--;
            }
            if(nums[(i + count) % nums.size()]){
                a++;
            }

            countone = max(countone, a);
        }

        return (count - countone);

    }
};

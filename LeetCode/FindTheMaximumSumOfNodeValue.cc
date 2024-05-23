//Question: https://leetcode.com/problems/find-the-maximum-sum-of-node-values/description/?envType=daily-question&envId=2024-05-19
//Level: Hard

//Solution: 
class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        

        long long int countxor = 0;
        long long int total = 0;
        long long int count = 0;

        for(int i = 0; i < nums.size(); i++){
            if((nums[i] ^ k) > nums[i]){
                countxor++;
            }
        }

        if((countxor % 2 == 0)){
            for(int i = 0; i < nums.size(); i++)
                count += ((nums[i] ^ k) > nums[i]) ? (nums[i] ^ k) : nums[i];
        }

        else{
            int mini = INT_MAX;

            for(int i = 0; i < nums.size(); i++){
                if((nums[i] ^ k) > nums[i])
                    mini = min(mini, (abs((nums[i] ^ k) - nums[i])));

            }
            int minnot = INT_MAX;
            for(int i = 0; i < nums.size(); i++){
                if((nums[i] ^ k) < nums[i])
                    minnot = min(minnot, abs((nums[i] ^ k) - nums[i]));
            }

            for(int i = 0; i < nums.size(); i++)
                count += ((nums[i] ^ k) > nums[i]) ? (nums[i] ^ k) : nums[i];



            // if(((minnot ^ k) + (mini ^ k)) < (minnot + mini))
            //     count -= minnot;
            // else if(((minnot ^ k) + (mini ^ k)) > (minnot + mini))
            //     count -= mini;
            // else
                count -= min(mini, minnot);


        }

        return count;

    }
};
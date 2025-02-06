//Question: https://leetcode.com/problems/tuple-with-same-product/?envType=daily-question&envId=2025-02-06
//Level: Medium

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {

        int ans = 0;
        unordered_map<int, int> mapp;

        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j < nums.size(); j++){
                if(i != j) mapp[nums[i] * nums[j]]++;
            }
        }

        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j < nums.size(); j++){
                int temp = mapp[nums[i] * nums[j]];

                if(i != j){
                    if(temp > 2) ans += (temp - 2);
                }

            }
        }

        return ans;

    }
};

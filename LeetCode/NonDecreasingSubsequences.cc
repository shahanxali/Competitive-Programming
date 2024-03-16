//Question: https://leetcode.com/problems/non-decreasing-subsequences/
//Level: Medium

class Solution {
public:

    vector<vector<int>> ans;

    void backtrack(vector<int>& nums, vector<int>& temp, int start){

        if(temp.size() >= 2){
            ans.push_back(temp);
        }

        unordered_set<int> used;

        for(int i = start; i < nums.size(); i++){

            if(used.count(nums[i])) continue;

            if(temp.empty() || nums[i] >= temp.back()){
                temp.push_back(nums[i]);
                backtrack(nums, temp, i + 1);
                temp.pop_back();
                used.insert(nums[i]);
            }
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> temp;
        backtrack(nums,temp,0);
        return ans;
    }
};

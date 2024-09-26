//Question: https://leetcode.com/problems/permutations-ii/
//Level: Medium

class Solution {
public:

    void backtrack(vector<int> nums, vector<vector<int>>& ans, vector<int> temp, vector<bool> check){

        if(temp.size() == nums.size()){
            ans.push_back(temp);
            return;
        }

        unordered_map<int, bool> c;

        for(int i = 0; i < nums.size(); i++){

            if(!check[i] && !c[nums[i]]){

                c[nums[i]] = true;
                check[i] = true;
                temp.push_back(nums[i]);

                backtrack(nums, ans, temp, check);

                check[i] = false;
                temp.pop_back();

            }

        }

        return;

    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> temp;
        vector<bool> check(nums.size(), false);

        backtrack(nums, ans, temp, check);

        return ans;

    }
};

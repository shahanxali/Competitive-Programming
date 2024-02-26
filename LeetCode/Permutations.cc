//Question: https://leetcode.com/problems/permutations/
//Level: Medium

class Solution {
public:

    vector<vector<int>> ans;
    map<int, bool> ansmap;


    void backtrack(vector<int>& nums, vector<int>& curr) {
        if (curr.size() == nums.size()) {
            ans.push_back(curr);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (!ansmap[nums[i]]) {
                curr.push_back(nums[i]);
                ansmap[nums[i]] = true;
                backtrack(nums, curr);
                curr.pop_back();
                ansmap[nums[i]] = false;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> curr;
        backtrack(nums,curr);
        return ans;
    }
};
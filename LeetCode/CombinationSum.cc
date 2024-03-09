//Question: https://leetcode.com/problems/combination-sum/
//Level: Medium

//Backtrack

class Solution {
public:
    vector<vector<int>> ans;

    void backtrack(vector<int>& candidate, int target, vector<int>& rn, int start) {
        if (target == 0) {
            ans.push_back(rn);
            return;
        }

        for (int i = start; i < candidate.size(); i++) {
            if (target - candidate[i] >= 0) {
                rn.push_back(candidate[i]);
                backtrack(candidate, target - candidate[i], rn, i); 
                rn.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> rn;
        backtrack(candidates, target, rn, 0);
        return ans;
    }
};

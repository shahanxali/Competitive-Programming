//Question: https://leetcode.com/problems/combination-sum-ii/description/?envType=daily-question&envId=2024-08-13
//Level: Medium

class Solution {
public:

    void backtrack(vector<int> candidates, int target, int index, vector<int> temp, vector<vector<int>> &ans){

        if(target == 0){
            ans.push_back(temp);
            return;
        }

        for(int i = index; i < candidates.size(); i++){
            if (i > index && candidates[i] == candidates[i - 1]) continue;
            else{
                if(target >= candidates[i]){
                    temp.push_back(candidates[i]);
                    backtrack(candidates, target - candidates[i], i + 1, temp, ans);
                    temp.pop_back();
                }
            }

        }

        return;

    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0, temp, ans);
    
        return ans;

    }
};
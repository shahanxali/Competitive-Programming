//Question: https://leetcode.com/problems/final-array-state-after-k-multiplication-operations-i/
//Level: Medium

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        
        vector<pair<int, int>> store;

        for(int i = 0; i < nums.size(); i++){
            store.push_back({nums[i], i});
        }

        while(k--){

            sort(store.begin(), store.end());
            store[0].first *= multiplier;

        }

        vector<int> ans(nums.size(), 0);

        for(int i = 0; i < store.size(); i++){
            ans[store[i].second] = store[i].first;
        }

        return ans;

    }
};
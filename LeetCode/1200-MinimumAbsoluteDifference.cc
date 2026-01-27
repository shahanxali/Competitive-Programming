//Question: https://leetcode.com/problems/minimum-absolute-difference/?envType=daily-question&envId=2026-01-26
//Level: Easy

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        int mini = INT_MAX;
        vector<vector<int>> ans;

        for(int i = 0; i < arr.size() - 1; i++){
            mini = min(mini, arr[i + 1] - arr[i]);
        }

        for(int i = 0; i < arr.size() - 1; i++){
            if(arr[i + 1] - arr[i] == mini) ans.push_back({arr[i], arr[i + 1]});
        }

        return ans;
    }
};

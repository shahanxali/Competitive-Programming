//Question: https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/?envType=daily-question&envId=2025-02-27
//Level: Medium

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {

        if(arr.size() <= 2) return 0;

        vector<vector<int>> dp(arr.size(), vector<int>(arr.size(), 2));
        unordered_map<int, int> store;

        for(int i = 0; i < arr.size(); i++) store[arr[i]] = i;

        for(int i = 1; i < arr.size(); i++){
            for(int j = i - 1; j >= 0; j--){

                int sub = arr[i] - arr[j];
                if(sub < arr[j] && store.count(sub)) dp[j][i] = dp[store[sub]][j] + 1;

            }
        }

        int ans = 0;

        for(auto a : dp){
            for(int b : a){
                ans = max(ans, b);
            }
        }

        return ans == 2 ? 0 : ans;

    }
};

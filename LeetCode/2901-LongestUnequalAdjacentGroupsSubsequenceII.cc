//Question: https://leetcode.com/problems/longest-unequal-adjacent-groups-subsequence-ii/description/?envType=daily-question&envId=2025-05-16
//Level: Medium

class Solution {
public:

    bool check(vector<string>& words, vector<int>& groups, int i, int j){
        if(words[i].size() != words[j].size() || groups[i] == groups[j]) return false;
        int count = 0;
        for(int k = 0; k < words[i].size(); k++){
            if(count >= 2) return false;
            if(words[i][k] != words[j][k]) count++;
        }
        return count == 1;
    }

    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {

        int n = words.size();
        vector<int> dp(n, 1), parent(n, -1);
        vector<string> ans;
        int maxi = 1, index = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(check(words, groups, i, j) && dp[j] + 1 > dp[i]){
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }
            if(dp[i] > maxi){
                maxi = dp[i];
                index = i;
            }
        }

        while(index != -1){
            ans.push_back(words[index]);
            index = parent[index];
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

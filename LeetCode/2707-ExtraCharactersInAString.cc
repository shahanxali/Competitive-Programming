//Question: https://leetcode.com/problems/extra-characters-in-a-string/?envType=daily-question&envId=2024-09-23
//Level: Medium

class Solution {
public:

    int minExtraChar(string s, vector<string>& dictionary) {

        unordered_set<string> store(dictionary.begin(), dictionary.end());
        int n = s.size();

        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i <= n; i++) {

            for (int j = 0; j < i; j++) {
                string current = s.substr(j, i - j);

                if (store.find(current) != store.end()) {
                    dp[i] = min(dp[i], dp[j]);
                } else {
                    dp[i] = min(dp[i], dp[j] + (int)current.size());
                }
            }
        }

        return dp[n];

    }
};

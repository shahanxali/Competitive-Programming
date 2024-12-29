//Question: https://leetcode.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary/?envType=daily-question&envId=2024-12-29
//Level: Hard

class Solution {
public:
    int mod = 1e9 + 7;

    int helper(int i, int j, vector<string>& words, string& target, vector<vector<int>>& store, vector<vector<int>>& memo) {

        if (i == target.size()) return 1;

        if (j == words[0].size()) return 0;

        if (memo[i][j] != -1) return memo[i][j];

        long long result = helper(i, j + 1, words, target, store, memo);

        if (store[target[i] - 'a'][j] > 0) {
            result += (1LL * store[target[i] - 'a'][j] * helper(i + 1, j + 1, words, target, store, memo)) % mod;
            result %= mod;
        }

        return memo[i][j] = result;
    }

    int numWays(vector<string>& words, string target) {
        int n = words[0].size();

        vector<vector<int>> store(26, vector<int>(n, 0));
        for (const auto& word : words) {
            for (int j = 0; j < n; j++) {
                store[word[j] - 'a'][j]++;
            }
        }

        vector<vector<int>> memo(target.size(), vector<int>(n, -1));

        return helper(0, 0, words, target, store, memo);
    }
};

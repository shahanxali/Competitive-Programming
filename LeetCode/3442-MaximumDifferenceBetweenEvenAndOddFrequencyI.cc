//Questoin: https://leetcode.com/problems/maximum-difference-between-even-and-odd-frequency-i/?envType=daily-question&envId=2025-06-10
//Level: Easy

class Solution {
public:
    int maxDifference(string s) {

        unordered_map<char, int> mapp;
        for(char c : s) mapp[c]++;

        int maxi = -1, mini = INT_MAX;

        for(auto pair : mapp){
            if(pair.second % 2 != 0) maxi = max(maxi, pair.second);
            else mini = min(mini, pair.second);
        }

        return maxi - mini;

    }
};

//Question: https://leetcode.com/problems/find-longest-special-substring-that-occurs-thrice-i/?envType=daily-question&envId=2024-12-10
//Level: Medium

class Solution {
public:
    int maximumLength(string s) {

        unordered_map<string, int> mapp;
        bool check = false;

        for(int i = 0; i < s.size(); i++){
            for(int j = 1; j <= s.size() - i; j++){

                if(s[i] != s[i + j - 1]){
                    break;
                }

                mapp[s.substr(i, j)]++;
            }
        }

        int ans = -1;

        for(auto pair : mapp){
            if(pair.second >= 3) ans = max(ans, int(pair.first.size()));
        }

        return ans;

    }
};

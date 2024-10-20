//Question: https://leetcode.com/contest/weekly-contest-420/problems/count-substrings-with-k-frequency-characters-i/
//Level: Medium

class Solution {
public:
    int numberOfSubstrings(string s, int k) {

        int ans = 0;

        for(int i = 0; i < s.size(); i++){
            map<char, int> mapp;
            bool temp = false;
            for(int j = i; j < s.size(); j++){

                mapp[s[j]]++;
                if(mapp[s[j]] >= k) temp = true;
                if(temp) ans++;

            }
        }

        return ans;

    }
};

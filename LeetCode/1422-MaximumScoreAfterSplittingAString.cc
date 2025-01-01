//Question: https://leetcode.com/problems/maximum-score-after-splitting-a-string/?envType=daily-question&envId=2025-01-01
//Level: Easy

class Solution {
public:
    int maxScore(string s) {

        int z = 0, o = 0;

        for(auto num : s){
            if(num == '1') o++;
        }

        if(s[0] == '1') o--;
        else z++;

        int ans = o + z;

        for(int i = 1; i < s.size() - 1; i++){
            char num = s[i];
            if(num == '1') o--;
            else z++;
            ans = max(ans, o + z);
        }

        return ans;

    }
};

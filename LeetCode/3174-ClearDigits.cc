//Question: https://leetcode.com/problems/clear-digits/?envType=daily-question&envId=2025-02-10
//Level: Easy

class Solution {
public:
    string clearDigits(string s) {

        vector<bool> check(s.size(), true);

        for(int i = 0; i < s.size(); i++){
            if(isdigit(s[i])) check[i] = false;
        }

        int count = 0;

        for(int i = s.size() - 1; i >= 0; i--){
            if(!check[i]) count++;
            else{
                if(count > 0){
                    count--;
                    check[i] = false;
                    continue;
                }
            }
        }

        string ans = "";

        for(int i = 0; i < s.size(); i++){
            if(check[i]) ans += s[i];
        }

        return ans;

    }
};

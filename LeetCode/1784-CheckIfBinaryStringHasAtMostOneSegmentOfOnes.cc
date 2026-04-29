//Question: https://leetcode.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones/description/?envType=daily-question&envId=2026-03-06
//Level: Easy

class Solution {
public:
    bool checkOnesSegment(string s) {

        bool cont = false;

        for(int i = 0; i < s.size(); i++){

            if(s[i] == '1'){
                if(cont) return false;
                while(i < s.size() && s[i] == '1'){
                    i++;
                    cont = true;
                }
            }

        }

        return true;

    }
};

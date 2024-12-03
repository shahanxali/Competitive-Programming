//Question: https://leetcode.com/problems/adding-spaces-to-a-string/?envType=daily-question&envId=2024-12-03
//Level: Medium

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {

        string ans = "";
        int point = 0, count = 0;

        for(auto c : s){

            if(point < spaces.size() && count == spaces[point]){
                ans += ' ';
                point++;
            }
            ans += c;
            count++;

        }

        return ans;


    }
};

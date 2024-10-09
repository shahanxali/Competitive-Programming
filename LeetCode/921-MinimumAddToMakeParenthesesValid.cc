//Question: https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/description/?envType=daily-question&envId=2024-10-09
//Level: Medium

class Solution {
public:
    int minAddToMakeValid(string s) {

        vector<char> stack;

        int op = 0, clo = 0;

        for(auto c : s){

            if(c == '('){
                stack.push_back(c);
            }
            else if(c == ')' && !stack.empty()){
                stack.pop_back();
            }
            else{
                clo++;
            }

        }
        op = stack.size();

        return clo + op;

    }
};

//Question: https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/description/?envType=daily-question&envId=2024-04-06
//Level: Medium

class Solution {
public:
    string minRemoveToMakeValid(string s) {
    
        vector<int> neg, pos;
        for(int i = 0; i < s.length(); i++){

            if(s[i] == '('){
                pos.push_back(i);
            }

            else if(s[i] == ')'){
                if(!pos.empty()){
                    pos.pop_back();
                }
                else{
                    neg.push_back(i);
                }
            }

        }

        for(int idx : neg){
            s[idx] = '*'; 
        }
        for(int idx : pos){
            s[idx] = '*';
        }

        string result;
        for(char c : s){
            if(c != '*')
            {
                result += c;
            }
        }

        return result;


    }
};
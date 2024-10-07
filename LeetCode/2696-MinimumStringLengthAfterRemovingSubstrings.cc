//Question: https://leetcode.com/problems/minimum-string-length-after-removing-substrings/?envType=daily-question&envId=2024-10-07
//Level: Easy


class Solution {
public:
    int minLength(string s) {

        vector<char> stack;

        for(int i = 0; i < s.size(); i++){

            if(!stack.empty()){
                if(s[i] == 'B' && stack.back() == 'A'){
                    stack.pop_back();
                }
                else if(s[i] == 'D' && stack.back() == 'C'){
                    stack.pop_back();
                }
                else{
                    stack.push_back(s[i]);
                }
            }
            else{
                stack.push_back(s[i]);
            }

        }

        return stack.size();

    }
};

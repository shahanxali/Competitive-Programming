//Question: https://leetcode.com/problems/valid-parentheses/
//Level: Easy

class Solution {
public:
    bool isValid(string s) {

        vector<int> stack;

        for(int i = 0; i < s.size(); i++){

            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                stack.push_back(s[i]);
            }
            else{

                if (stack.empty()) {
                    return false;
                }

                if((s[i] == ')' && stack.back() == '(') ||
                    (s[i] == ']' && stack.back() == '[') ||
                    (s[i] == '}' && stack.back() == '{')){
                        stack.pop_back();
                }
                else{
                    return false;
                }
            }

        }

        return stack.empty();

    }
};

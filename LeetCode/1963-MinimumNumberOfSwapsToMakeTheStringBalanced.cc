//Question: https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/description/?envType=daily-question&envId=2024-10-08
//Level: Medium

class Solution {
public:
    int minSwaps(string s) {

        int op = 0, clo = 0, ancount = 0;
        vector<char> stack;

        for(auto c : s){
            if(c == '['){
                stack.push_back(c);
            }
            if(c == ']'){
                if(stack.empty()){
                    ancount++;
                }
                else stack.pop_back();
            }
        }

        return ancount % 2 == 0 ? ancount / 2 : (ancount + 1) / 2;


    }
};

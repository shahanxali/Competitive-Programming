//Question: https://leetcode.com/problems/neighboring-bitwise-xor/?envType=daily-question&envId=2025-01-17
//Level: Medium

class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {

        int start = 1;
        for(int i = 0; i < derived.size(); i++){
            if(derived[i] == 1) start = (start == 0) ? 1 : 0;
        }

        return start == 1;

    }
};

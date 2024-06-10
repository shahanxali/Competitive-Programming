//Question: https://leetcode.com/problems/height-checker/description/?envType=daily-question&envId=2024-06-10
//Level: Easy

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        
        vector<int> exp = heights;
        sort(exp.begin(), exp.end());

        int count = 0;

        for(int i = 0; i < exp.size(); i++){
            if(heights[i] != exp[i]){
                count++;
            }
        }

        return count;

    }
};

//Question: https://leetcode.com/contest/weekly-contest-415/problems/the-two-sneaky-numbers-of-digitville/
//Level: Easy

class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {

        map<int, int> mapp;

        for(int i = 0; i < nums.size(); i++){
            mapp[nums[i]]++;
        }

        vector<int> ans;

        for(auto pair: mapp){
            if(pair.second >= 2){
                ans.push_back(pair.first);
            }
        }

        return ans;


    }
};

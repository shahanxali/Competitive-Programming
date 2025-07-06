//Question: https://leetcode.com/problems/find-lucky-integer-in-an-array/description/?envType=daily-question&envId=2025-07-05
//Level: Easy

class Solution {
public:
    int findLucky(vector<int>& arr) {

        unordered_map<int, int> store;
        for(int a : arr) store[a]++;

        int ans = -1;
        for(auto pair : store){
            if(pair.second == pair.first) ans = max(ans, pair.first);
        }

        return ans;

    }
};

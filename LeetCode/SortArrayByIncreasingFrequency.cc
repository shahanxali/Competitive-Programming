//Question: https://leetcode.com/problems/sort-array-by-increasing-frequency/?envType=daily-question&envId=2024-07-23
//Level: Easy

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        
        map<int, int> store;
        for(int i = 0; i < nums.size(); i++){
            store[nums[i]]++;
        }
        vector<pair<int, int>> so(store.begin(), store.end());
        
        sort(so.begin(),so.end(), [](pair<int, int> &p1, pair<int, int> &p2){
            if(p1.second == p2.second){
                return p1.first > p2.first;
            }
            return p1.second < p2.second;
        });

        vector<int> ans;
        for(int i = 0; i < so.size(); i++){

            for(int j = 0; j < so[i].second; j++){
                ans.push_back(so[i].first);
            }

        }

        return ans;

    }
};

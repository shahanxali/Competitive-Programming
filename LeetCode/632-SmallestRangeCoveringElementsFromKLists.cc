//Question: https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/
//Level: Hard

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {

        vector<pair<int, int>> store;

        int start = 0;

        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j < nums[i].size(); j++){
                store.push_back({i, nums[i][j]});
            }
        }

        sort(store.begin(), store.end(), [](pair<int, int> a1, pair<int, int> a2){
            return a1.second < a2.second;
        });

        unordered_map<int, int> freq;

        vector<int> ans = {-100000, 100000};

        for(int i = 0; i < store.size(); i++){

            freq[store[i].first]++;

            while(freq.size() == nums.size()){

                if(ans[1] - ans[0] > store[i].second - store[start].second){
                    ans[1] = store[i].second;
                    ans[0] = store[start].second;
                }

                freq[store[start].first]--;
                if(freq[store[start].first] == 0) freq.erase(store[start].first);

                start++;

            }

        }

        return ans;


    }
};

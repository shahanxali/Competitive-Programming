//Question: https://leetcode.com/problems/rank-transform-of-an-array/description/?envType=daily-question&envId=2024-10-02
//Level: Medium

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {

        if(arr.size() == 0){
            return {};
        }

        vector<pair<int, int>> store;
        vector<int> ans(arr.size());

        for(int i = 0; i < arr.size(); i++){
            store.push_back({arr[i], i});
        }

        sort(store.begin(), store.end(), [](pair<int, int> a, pair<int, int> b){
            return a.first < b.first;
        });

        int count = 0;
        for(int i = 0; i < store.size(); i++){
            count++;
            ans[store[i].second] = count;
            cout << ans[store[i].second];
            while(i < store.size() - 1 && store[i].first == store[i + 1].first){
                i++;
                ans[store[i].second] = count;
            }

        }

        return ans;

    }
};

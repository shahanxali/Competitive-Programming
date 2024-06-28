//Question: https://leetcode.com/problems/maximum-total-importance-of-roads/description/?envType=daily-question&envId=2024-06-28
//Level: Medium

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        
        map<int, int> mapp;

        for(int i = 0; i < roads.size(); i++){

            mapp[roads[i][0]]++;
            mapp[roads[i][1]]++;
            
        }
        vector<pair<int, int>> store;

        for(const auto pair : mapp){
            store.push_back({pair.first, pair.second});
        }

        sort(store.begin(), store.end(), [](pair<int, int>& pair1, pair<int, int>& pair2){ return (pair1.second > pair2.second);});

        long long count = 0;


        for(int i = 0; i < store.size(); i++){

            mapp[store[i].first] = n;
            n--;

        }

        for(int i = 0; i < roads.size(); i++){
            count += (mapp[roads[i][0]] + mapp[roads[i][1]]);
        }

        return count;

    }
};

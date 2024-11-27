//Question: https://leetcode.com/problems/shortest-distance-after-road-addition-queries-i/?envType=daily-question&envId=2024-11-27
//Level: Medium

class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {

        vector<int> store(n);
        for(int i = 0; i < n; i++){
            store[i] = i;
        }

        vector<vector<int>> graph(n);

        for(int i = 1; i < n; i++){
            graph[i].push_back(i - 1);
        }

        vector<int> ans;

        for(int i = 0; i < queries.size(); i++){

            int a = queries[i][0], b = queries[i][1];
            graph[b].push_back(a);

            for(int k = b; k < n; k++){
                for(int j = 0; j < graph[k].size(); j++){
                    store[k] = min(store[k], store[graph[k][j]] + 1);
                }
            }
            ans.push_back(store[n - 1]);
        }

        return ans;

    }
};

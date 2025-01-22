//Question: https://leetcode.com/problems/map-of-highest-peak/?envType=daily-question&envId=2025-01-22
//Level: Medium

class Solution {
public:

    vector<vector<int>> bfs(vector<vector<int>> isWater){

        int m = isWater.size(), n = isWater[0].size();
        vector<vector<int>> graph(m, vector<int> (n, -1));
        vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        queue<vector<int>> q;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(isWater[i][j] == 1){
                    graph[i][j] = 0;
                    q.push({0, i, j});
                }
            }
        }

        while(!q.empty()){

            auto tempv = q.front();
            q.pop();
            int val = tempv[0], x = tempv[1], y = tempv[2];


            for(auto d : dir){
                int newx = x + d[0], newy = y + d[1];

                if(newx >= m || newx < 0 || newy < 0 || newy >= n) continue;

                if(graph[newx][newy] == -1){
                    graph[newx][newy] = val + 1;
                    q.push({val + 1, newx, newy});
                }
            }

        }

        return graph;

    }

    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {

        return bfs(isWater);

    }
};

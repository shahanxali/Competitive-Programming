//Question: https://leetcode.com/problems/maximum-number-of-fish-in-a-grid/?envType=daily-question&envId=2025-01-28
//Level: Medium

class Solution {
public:

    int topol(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j){

        int tempans = 0, m = grid.size(), n = grid[0].size();
        queue<vector<int>> q;
        vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};


        q.push({i, j});
        visited[i][j] = true;

        while(!q.empty()){

            int x = q.front()[0], y = q.front()[1];
            q.pop();
            tempans += grid[x][y];

            for(auto d : dir){
                int newx = x + d[0], newy = y + d[1];

                if(newx < 0 || newy < 0 || newx >= m || newy >= n) continue;

                if(!visited[newx][newy] && grid[newx][newy] != 0){
                    visited[newx][newy] = true;
                    q.push({newx, newy});
                }

            }

        }

        return tempans;

    }

    int findMaxFish(vector<vector<int>>& grid) {

        int ans = 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool> (n, false));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] != 0 && !visited[i][j]){
                    ans = max(ans, topol(grid, visited, i, j));
                }
            }
        }

        return ans;

    }
};

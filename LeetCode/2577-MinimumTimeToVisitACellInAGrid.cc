//Question: https://leetcode.com/problems/minimum-time-to-visit-a-cell-in-a-grid/description/?envType=daily-question&envId=2024-11-29
//Level: Hard

class Solution {
public:

    bool isvalid(int i, int j, pair<int, int> direction, int m, int n){
        i += direction.first;
        j += direction.second;
        return i >= 0 && j >= 0 && i < m && j < n;
    }

    int djikstra(vector<vector<int>> grid, int m, int n){

        vector<vector<int>> store(m, vector<int> (n, INT_MAX));

        //pair<int, int> pq = {dist, {location i, j}};
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        pq.push({0, {0, 0}});
        vector<pair<int, int>> direction = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        if(grid[0][1] > 1 && grid[1][0] > 1) return -1;

        while(!pq.empty()){

            int pos = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();

            for(int k = 0; k < 4; k++){

                if(isvalid(i, j, direction[k], m, n)){

                    int newi = i + direction[k].first;
                    int newj = j + direction[k].second;

                    if(grid[newi][newj] <= pos + 1 && pos + 1  < store[newi][newj]){
                        pq.push({pos + 1, {newi, newj}});
                        store[newi][newj] = pos + 1;
                    }
                    else if(grid[newi][newj] > pos + 1){
                        if(pos % 2 == 0 && grid[newi][newj] % 2 == 0 || pos % 2 != 0 && grid[newi][newj] % 2 != 0){
                            pq.push({grid[newi][newj] + 1, {newi, newj}});
                            store[newi][newj] = grid[newi][newj] + 1;
                        }
                        else{
                            pq.push({grid[newi][newj], {newi, newj}});
                            store[newi][newj] = grid[newi][newj];
                        }
                    }


                }

            }

        }

        return store[m - 1][n - 1];

    }

    int minimumTime(vector<vector<int>>& grid) {

        int m = grid.size(), n = grid[0].size();

        return djikstra(grid, m, n);

    }
};

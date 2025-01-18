//Question: https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/description/?envType=daily-question&envId=2025-01-18
//Level: Hard

class Solution {
public:
    int djikstra(vector<vector<int>> &grid) {

        int m = grid.size();
        int n = grid[0].size();

        // Directions: 1 → right, 2 → left, 3 → down, 4 → up
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        vector<vector<int>> cost(m, vector<int>(n, INT_MAX));

        // Min-heap: {current cost, row, col}
        priority_queue<vector<int>, vector<vector<int>>, greater<>> q;
        cost[0][0] = 0;
        q.push({0, 0, 0});

        while (!q.empty()) {

            auto current = q.top();
            q.pop();

            int curCost = current[0], x = current[1], y = current[2];


            for (int d = 0; d < 4; d++) {
                int newX = x + directions[d][0];
                int newY = y + directions[d][1];
                if (newX < 0 || newY < 0 || newX >= m || newY >= n) continue;

                int newCost = curCost + (grid[x][y] == d + 1 ? 0 : 1);
                if (newCost < cost[newX][newY]) {
                    cost[newX][newY] = newCost;
                    q.push({newCost, newX, newY});
                }


            }

        }

        return cost[m - 1][n - 1];

    }

    int minCost(vector<vector<int>> &grid) {

        return djikstra(grid);

    }
};

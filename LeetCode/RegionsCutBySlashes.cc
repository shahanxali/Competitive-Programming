//Question: https://leetcode.com/problems/regions-cut-by-slashes/description/?envType=daily-question&envId=2024-08-10
//Level: Medium

//Concept: Disjoint Sets


class Solution {
public:
    map<vector<int>, vector<int>> store;

    vector<int> find(vector<int> a) {
        if (store.find(a) == store.end()) {
            store[a] = a;
        }
        if (store[a] != a) {
            store[a] = find(store[a]);
        }
        return store[a];
    }

    void unionset(vector<int> a, vector<int> b) {
        vector<int> x = find(a);
        vector<int> y = find(b);

        if (x != y) {
            store[x] = y;
        }
    }

    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        
        // Loop through each cell in the grid
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // Handle current cell
                if (grid[i][j] == '/') {
                    unionset({i, j, 0}, {i, j, 3});
                    unionset({i, j, 1}, {i, j, 2});
                } else if (grid[i][j] == '\\') {
                    unionset({i, j, 0}, {i, j, 1});
                    unionset({i, j, 2}, {i, j, 3});
                } else {
                    unionset({i, j, 0}, {i, j, 1});
                    unionset({i, j, 1}, {i, j, 2});
                    unionset({i, j, 2}, {i, j, 3});
                }

                // Union with adjacent cells
                if (i > 0) {
                    unionset({i, j, 0}, {i - 1, j, 2});
                }
                if (j > 0) {
                    unionset({i, j, 3}, {i, j - 1, 1});
                }
            }
        }

        // Count unique regions by counting the unique parents
        int regions = 0;
        for (auto& kv : store) {
            if (kv.first == kv.second) {
                regions++;
            }
        }

        return regions;
    }
};


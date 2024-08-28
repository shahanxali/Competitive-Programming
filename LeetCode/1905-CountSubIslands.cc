//Question: https://leetcode.com/problems/count-sub-islands/description/
//Level: Medium


class Solution {
public:

    void dfs(vector<vector<int>>& grid2, int s, int e, vector<vector<bool>>& check, bool& yesorno, vector<vector<int>>& grid1) {

        vector<pair<int, int>> stack;
        stack.push_back({s, e});
        if(grid1[s][e] == 0) {
            yesorno = false;
        }
        check[s][e] = true;

        vector<pair<int, int>> pairs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

        while(!stack.empty()) {
            s = stack.back().first;
            e = stack.back().second;
            stack.pop_back();

            for(auto it : pairs) {
                int newX = s + it.first;
                int newY = e + it.second;
                int rows = grid2.size();
                int cols = grid2[0].size();

                if(newX < rows && newY < cols && newX >= 0 && newY >= 0 && grid2[newX][newY] == 1 && !check[newX][newY]) {
                    stack.push_back({newX, newY});
                    if(grid1[newX][newY] == 0) {
                        yesorno = false;
                    }
                    check[newX][newY] = true;
                }
            }
        }
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        
        int m = grid1.size();
        int n = grid1[0].size();
        vector<vector<bool>> check(m, vector<bool>(n, false));
        int ans = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(grid2[i][j] == 1 && !check[i][j]) {
                    bool yesorno = true;
                    dfs(grid2, i, j, check, yesorno, grid1);

                    if(yesorno) {
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};


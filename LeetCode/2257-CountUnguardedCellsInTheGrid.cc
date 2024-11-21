//Question: https://leetcode.com/problems/count-unguarded-cells-in-the-grid/?envType=daily-question&envId=2024-11-21
//Level: Medium

class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& gaurds, vector<vector<int>>& walls) {

        vector<vector<int>> store(m, vector<int> (n, 0));
        int ans = m * n - (gaurds.size() + walls.size());

        for(int i = 0; i < gaurds.size(); i++){
            store[gaurds[i][0]][gaurds[i][1]] = 2;
        }
        for(int i = 0; i < walls.size(); i++){
            store[walls[i][0]][walls[i][1]] = 2;
        }

        for(int i = 0; i < gaurds.size(); i++){

            //Right
            int a = gaurds[i][0], b = gaurds[i][1];
            a++;
            while(a < store.size() && store[a][b] != 2){
                if(store[a][b] == 0){
                    store[a][b] = 1;
                    ans--;
                }
                a++;
            }

            //down
            a = gaurds[i][0], b = gaurds[i][1];
            b++;
            while(b < store[0].size() && store[a][b] != 2){
                if(store[a][b] == 0){
                    store[a][b] = 1;
                    ans--;
                }
                b++;
            }

            //Left
            a = gaurds[i][0], b = gaurds[i][1];
            a--;
            while(a >= 0 && store[a][b] != 2){
                if(store[a][b] == 0){
                    store[a][b] = 1;
                    ans--;
                }
                a--;
            }

            //Up
            a = gaurds[i][0], b = gaurds[i][1];
            b--;
            while(b >= 0 && store[a][b] != 2){
                if(store[a][b] == 0){
                    store[a][b] = 1;
                    ans--;
                }
                b--;
            }

        }


        return ans;

    }
};

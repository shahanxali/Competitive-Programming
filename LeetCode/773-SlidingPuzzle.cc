//Question: https://leetcode.com/problems/sliding-puzzle/description/?envType=daily-question&envId=2024-11-25
//Level: Hard

class Solution {
public:

    void bfs(string fin, int& count, string need, int pos){

        queue<pair<string, pair<int, int>>> q;
        unordered_set<string> visited;
        q.push({fin, {0, pos}});
        visited.insert(fin);

        vector<int> dir = {-3, -1, 3, 1};

        while(!q.empty()){

            string temp = q.front().first;
            int level = q.front().second.first;
            pos = q.front().second.second;
            q.pop();


            if(temp == need){
                count = level;
                return;
            }

            for(int i = 0; i < 4; i++){
                int newpos = pos + dir[i];

                if(newpos < 6 && newpos >= 0 &&
                !(pos == 2 && newpos == 3) && !(pos == 3 && newpos == 2)){

                    swap(temp[pos], temp[newpos]);
                    if(visited.find(temp) == visited.end()){
                        visited.insert(temp);
                        q.push({temp, {level + 1, newpos}});
                    }
                    swap(temp[pos], temp[newpos]);

                }
            }

        }

        count = -1;
        return;


    }

    int slidingPuzzle(vector<vector<int>>& board) {

        string fin = "";
        int a;
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 3; j++){
                fin += to_string(board[i][j]);
                if(board[i][j] == 0){
                    a = i * 3 + j;
                }
            }
        }

        int count = 0;

        bfs(fin, count, "123450", a);

        return count;

    }
};

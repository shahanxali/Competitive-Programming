//Question: https://leetcode.com/problems/letter-tile-possibilities/?envType=daily-question&envId=2025-02-17
//Level: Medium

class Solution {
public:

    void backtrack(string tiles, unordered_set<string> &store, string temp, vector<bool> visited){

        if(temp.size() == tiles.size()) return;

        for(int i = 0; i < tiles.size(); i++){

            string newstring = temp + tiles[i];

            if(store.find(newstring) == store.end() && !visited[i]){
                visited[i] = true;
                store.insert(newstring);
                backtrack(tiles, store, newstring, visited);
                visited[i] = false;
            }

        }

        return;

    }

    int numTilePossibilities(string tiles) {

        unordered_set<string> store;
        vector<bool> visited(tiles.size(), false);

        backtrack(tiles, store, "", visited);

        return store.size();

    }
};

//Question: https://leetcode.com/problems/find-champion-ii/?envType=daily-question&envId=2024-11-26
//Level: Medium

class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {

        vector<int> store(n);

        for(int i = 0; i < edges.size(); i++){
            store[edges[i][1]]++;
        }

        int c = 0, ans = 0;

        for(int i = 0; i < n; i++){
            if(store[i] == 0){
                c++;
                ans = i;
            }
        }

        if(c >= 2) return -1;
        return ans;

    }
};

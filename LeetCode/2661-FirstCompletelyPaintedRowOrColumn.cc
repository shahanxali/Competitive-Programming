//Question: https://leetcode.com/problems/first-completely-painted-row-or-column/?envType=daily-question&envId=2025-01-20
//Level: Medium

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {

        int m = mat.size(), n = mat[0].size(), k = arr.size();
        vector<pair<int, int>> store(k);
        vector<int> row(m, n), col(n, m);

        for(int i = 0; i < mat.size(); i++){
            for(int j = 0; j < mat[0].size(); j++){
                store[mat[i][j] - 1] = {i, j};
            }
        }

        for(int i = 0; i < k; i++){
            int first = store[arr[i] - 1].first, second = store[arr[i] - 1].second;

            row[first]--;
            col[second]--;

            if(row[first] == 0 || col[second] == 0) return i;
        }

        return -1;

    }
};

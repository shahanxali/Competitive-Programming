//Question: https://leetcode.com/problems/flip-columns-for-maximum-number-of-equal-rows/?envType=daily-question&envId=2024-11-22
//Level: Medium

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {

        vector<string> a, b;
        int ans = 0;

        for(int i = 0; i < matrix.size(); i++){
            string temp1 = "", temp2 = "";
            for(int j = 0; j < matrix[0].size(); j++){
                if(matrix[i][j] == 0) temp1 += to_string(j);
                else temp2 += to_string(j);
            }
            if(temp1.empty() || temp2.empty()) ans++;
            else{
                a.push_back(temp1);
                b.push_back(temp2);
            }
        }

        for(int i = 0; i < min(a.size(), b.size()); i++){
            if(a[i][0] < b[i][0]) swap(a[i], b[i]);
        }

        unordered_map<string, int> mapp;

        for(auto s : a){
            mapp[s]++;
        }

        for(auto num : mapp){
            ans = max(ans, num.second);
        }
        return ans;

    }
};

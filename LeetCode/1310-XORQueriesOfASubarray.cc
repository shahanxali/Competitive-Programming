//Question: https://leetcode.com/problems/xor-queries-of-a-subarray/
//Level: Medium

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {

        //The property used here is that a^b ^ (b+1)^d == a^d
        //And also a ^ b = c == a ^ c = b

        vector<int> store(arr.size());
        vector<int> ans(queries.size());

        store[0] = arr[0];
        for(int i = 1; i < arr.size(); i++){
            store[i] = store[i - 1] ^ arr[i];
        }

        for(int i = 0; i < queries.size(); i++){
            if(queries[i][0] == 0){
                ans[i] = store[queries[i][1]];
            }
            else{
                ans[i] = store[queries[i][0] - 1] ^ store[queries[i][1]];
            }
        }

        return ans;

    }
};

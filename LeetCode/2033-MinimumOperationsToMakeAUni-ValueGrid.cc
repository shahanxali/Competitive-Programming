//Question: https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/description/?envType=daily-question&envId=2025-03-26
//Level: Medium

class Solution {
    public:
        int minOperations(vector<vector<int>>& grid, int k) {
            
            vector<int> store;
            for(auto r : grid) for(auto l : r) store.push_back(l);
            sort(store.begin(), store.end());
            int temp = store[store.size() / 2], ans = 0;
    
            for(int i = 0; i < store.size(); i++){
                int check = abs(store[i] - temp);
                if(check % k != 0) return -1;
    
                ans += check / k;
            }
    
            return ans;
    
        }
    };

//Question: https://leetcode.com/problems/find-occurrences-of-an-element-in-an-array/description/
//Level: Medium

class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        
        vector<int> store;
        
        for(int i = 0; i < nums.size(); i++){
            
            if(nums[i] == x){
                store.push_back(i);
            }
            
        }

        
        vector<int> ans;
        
        for(int i = 0; i < queries.size(); i++){
            
            if(queries[i] > store.size()){
                ans.push_back(-1);
            }
            else{
                ans.push_back(store[queries[i] - 1]);
            }
            
        }
        
        return ans;
        
    }
};
//Quesion: https://leetcode.com/problems/find-the-xor-of-numbers-which-appear-twice/description/
//Level: Easy

class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        
        map<int, int> store;
        
        for(int i = 0; i < nums.size(); i++){
            store[nums[i]]++;
        }
        
        vector<int> ans;
        
        for(const auto pair : store){
            
            if(pair.second == 2){
                ans.push_back(pair.first);
            }
            
        }
        
        if(ans.size() == 0){
            return 0;
        }
        
        int x = ans[0];

        if(ans.size() == 1){
            return ans[0];
        }
        else if(ans.size() == 2){
            return ans[0] ^ ans[1];
        }
        for(int i = 1; i < ans.size(); i++){
            
            x = x ^ ans[i];
            
        }
        return x;
        
    }
};
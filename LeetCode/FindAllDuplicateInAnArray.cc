//Question: https://leetcode.com/problems/find-all-duplicates-in-an-array/
//Level: Medium

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        map<int,int> check;
        vector<int>arr;
        for(int i=0;i<nums.size();i++){
            if(check[nums[i]]!=2){
                check[nums[i]]++;
            }
            if(check[nums[i]]==2){
                arr.push_back(nums[i]);
            }
        }

        return arr;

    }
};
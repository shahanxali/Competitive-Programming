//Question: https://leetcode.com/problems/two-sum/description/
//Level: Easy



//Solution : 1 (two pointers method)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target){

        vector<pair<int, int>> ans;
        for(int i = 0; i < nums.size(); i++){
            ans[i].first = nums[i];
            ans[i].second = i;
        }

        sort(ans.begin(), ans.end(), [](const pair<int, int> &a, const pair<int, int> &b){
            return a.first > b.first;
        });

        int a = 0;
        int b = nums.size() - 1;

        while(a <= b){

            if(ans[a].first + ans[b].first > target){
                b--;
            }
            else if(ans[a].first + ans[b].first < target){
                a++;
            }
            else{
                return {ans[a].second, ans[b].second};
            }

        }

        return {0};

    }
};
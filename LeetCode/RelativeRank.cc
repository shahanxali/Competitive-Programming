//Question: https://leetcode.com/problems/relative-ranks/
//Level: Easy

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        
        vector<pair<int, int>> vec;
        for(int i = 0; i < score.size(); i++){

            vec.push_back({i,score[i]});

        }
        sort(vec.begin(), vec.end(), [](const pair<int, int> pair1, const pair<int, int> pair2){
            return pair1.second > pair2.second;
        });

        vector<string> ans(vec.size());

        for(int i = 0; i < vec.size(); i++){
            if(i == 0){
                ans[vec[i].first] = "Gold Medal";
            }
            else if(i == 1){
                ans[vec[i].first] = "Silver Medal";
            }
            else if(i == 2){
                ans[vec[i].first] = "Bronze Medal";
            }
            else{
                ans[vec[i].first] = to_string(i + 1);
            }
        }

        return ans;


    }
};
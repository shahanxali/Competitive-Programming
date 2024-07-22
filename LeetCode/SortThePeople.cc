//Question: https://leetcode.com/problems/sort-the-people/description/?envType=daily-question&envId=2024-07-22
//Level: Easy

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        
        vector<pair<int, string>> take;
        for(int i = 0; i < names.size(); i++){
            take.push_back({heights[i], names[i]});
        }
        sort(take.rbegin(), take.rend());
        
        for(int i = 0; i < take.size(); i++){
            names[i] = take[i].second;
        }

        return names;

    }
};

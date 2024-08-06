//Question: https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/description/
//Level: Medium

class Solution {
public:
    int minimumPushes(string word) {
        
        map<char, int, greater<char>> pp;

        for(int i = 0; i < word.size(); i++){
            pp[word[i]]++;
        }

        int count = 0, ans = 0;

        // vector<pair<char, int>> pp(store.begin(), store.end());
        // sort(pp.begin(), pp. end(), [](const pair<char, int>& p1, pair<char, int>& p2){
        //     return p1.second > p2.second;
        // });

        for(const auto& pair : pp){
            
            count++;
            int m = ((count % 8) == 0) ? ((count / 8) - 1) : (count / 8);
            ans += (pair.second * (m + 1));
        
        }

        return ans;

    }
};

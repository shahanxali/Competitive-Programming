//Question: https://leetcode.com/problems/find-words-containing-character/?envType=daily-question&envId=2025-05-24
//Level: Easy

class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {

        vector<int> ans;

        for(int i = 0; i < words.size(); i++){
            for(auto ch : words[i]){
                if(ch == x){
                    ans.push_back(i);
                    break;
                }
            }
        }

        return ans;

    }
};

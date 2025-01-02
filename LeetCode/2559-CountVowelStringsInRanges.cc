//Question: https://leetcode.com/problems/count-vowel-strings-in-ranges/?envType=daily-question&envId=2025-01-02
//Level: Medium

class Solution {
public:

    bool isvow(string word){
        char first = word[0], last = word[word.size() - 1];

        if(first == 'a' || first == 'e' || first == 'i' || first == 'o' || first == 'u'){
            if(last == 'a' || last == 'e' || last == 'i' || last == 'o' || last == 'u') return true;
        }

        return false;

    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {

        vector<int> store, ans;
        int count = 0;
        store.push_back(0);

        for(auto word : words){
            if(isvow(word)) store.push_back(++count);
            else store.push_back(count);
        }

        for(int i = 0; i < queries.size(); i++){
            ans.push_back(store[queries[i][1] + 1] - store[queries[i][0]]);
        }

        return ans;

    }
};

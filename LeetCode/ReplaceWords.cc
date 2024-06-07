//Question: https://leetcode.com/problems/replace-words/description/?envType=daily-question&envId=2024-06-07
//Level: Medium


class Solution {
public:
    string check(const string &a, const vector<pair<string, int>> &dictionary) {

        for (const auto &entry : dictionary) {
        
            const string &prefix = entry.first;
            if (a.substr(0, prefix.length()) == prefix) {
                return prefix;
            }
        
        }

        return a;
    
    }

    string replaceWords(vector<string>& dictionary, string sentence) {

        vector<pair<string, int>> store;
        for (const string &word : dictionary) {
            store.push_back({word, word.length()});
        }

        sort(store.begin(), store.end(), [](const pair<string, int> &p1, const pair<string, int> &p2) {
            return p1.second < p2.second;
        });

        istringstream iss(sentence);
        string word;
        string ans;


        //>> is used for the word by word reading of the sentence ignoring the space

        //Learn it lol
        while (iss >> word) {
            if (!ans.empty()) {
                ans += " ";
            }
            ans += check(word, store);
        }

        return ans;
    }
};

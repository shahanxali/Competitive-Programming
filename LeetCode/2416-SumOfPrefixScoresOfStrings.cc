//Question: https://leetcode.com/problems/sum-of-prefix-scores-of-strings/?envType=daily-question&envId=2024-09-25
//Level: Hard

struct TrieNode{
    unordered_map<char, pair<TrieNode*, int>> children;
};

class Solution {
public:

    void add(string s, TrieNode* head){

        TrieNode* temp = head;
        for(auto c : s){
            if (temp -> children.find(c) != temp -> children.end()) {
                temp -> children[c].second++;
            } else {
                temp -> children[c] = {new TrieNode(), 1};
            }
            temp = temp -> children[c].first;

        }

        return;

    }

    void search(string s, TrieNode* head, int& tempco){

        TrieNode* temp = head;
        for(auto c : s){
            if(temp -> children.find(c) != temp -> children.end()){
                tempco += temp -> children[c].second;
                temp = temp -> children[c].first;
            }
            else{
                break;
            }
        }

        return;

    }

    vector<int> sumPrefixScores(vector<string>& words) {

        TrieNode* head = new TrieNode();
        for(int i = 0; i < words.size(); i++){
            add(words[i], head);
        }

        vector<int> ans;

        for(int i = 0; i < words.size(); i++){
            int tempco = 0;
            search(words[i], head, tempco);
            ans.push_back(tempco);
        }

        return ans;

    }
};

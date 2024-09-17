//Question: https://leetcode.com/problems/uncommon-words-from-two-sentences/?envType=daily-question&envId=2024-09-17
//Level: Easy

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {

        unordered_map<string, int> store;
        vector<string> ans;
        string temp = "";

        string fin = s1 + " " + s2 + " ";

        for(int al = 0; al < fin.size(); al++){
            if(fin[al] == ' '){
                store[temp]++;
                temp = "";
            }
            else{
                temp += fin[al];
            }
        }

        for(auto pair : store){
            if(pair.second == 1){
                ans.push_back(pair.first);
            }
        }

        return ans;




    }
};

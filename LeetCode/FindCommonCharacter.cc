//Question: https://leetcode.com/problems/find-common-characters/description/?envType=daily-question&envId=2024-06-05
//Level: Easy

class Solution {
public:

    bool gon(char p, string &word) {
        for (int i = 0; i < word.length(); i++) {
            if (p == word[i]) {
                word[i] = ' '; 
                return true;
            }
        }
        return false;
    }

    vector<string> commonChars(vector<string>& words) {
        vector<string> ans;
        
        for (int i = 0; i < words[0].size(); i++) {
            char currentChar = words[0][i];
            bool isCommon = true;

            for (int k = 1; k < words.size(); k++) {
                if (!gon(currentChar, words[k])) {
                    isCommon = false;
                    break;
                }
            }

            if (isCommon) {
                ans.push_back(string(1, currentChar));
            }
        }

        return ans;
    }
};
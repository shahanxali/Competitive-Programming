//Question: https://leetcode.com/problems/word-break-ii/
//Level: Hard

class Solution {
public:
    
    vector<string> ans;

    void backtrack(string& s, unordered_set<string>& wordDict, int start, vector<string>& currentSentence) {
        
        if (start == s.length()) {
            
            string sentence;
            for (const string& word : currentSentence) {
                
                if (!sentence.empty()) {
                    sentence += " ";
                }
                sentence += word;
                
            }
            
            ans.push_back(sentence);
            
            return;
            
        }

        for (int end = start + 1; end <= s.length(); end++) {
            
            string word = s.substr(start, end - start);
            
            if (wordDict.find(word) != wordDict.end()) {
                
                currentSentence.push_back(word);
                
                backtrack(s, wordDict, end, currentSentence);
                
                currentSentence.pop_back();
                
            }
            
        }
        
        return;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        
        vector<string> currentSentence;
        backtrack(s, dict, 0, currentSentence);
        
        return ans;
        
    }
};


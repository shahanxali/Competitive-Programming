//Question: https://leetcode.com/problems/palindrome-partitioning/
//Level: Medium 

class Solution {
public:
    vector<vector<string>> ans;

    bool isPalindrome(const string& str) {
        int left = 0, right = str.size() - 1;
        while (left < right) {
            if (str[left] != str[right])
                return false;
            left++;
            right--;
        }
        return true;
    }

    void backtrack(string s, vector<string>& vec, int start) {
        if (start == s.size()) {
            ans.push_back(vec);
            return;
        }

        for (int i = start; i < s.size(); i++) {
            string substring = s.substr(start, i - start + 1);
            if (isPalindrome(substring)) {
                vec.push_back(substring);
                backtrack(s, vec, i + 1);
                vec.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        
        vector<string> vec;
        backtrack(s, vec, 0);
        return ans;

    }
};

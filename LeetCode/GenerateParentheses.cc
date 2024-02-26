//Question: https://leetcode.com/problems/generate-parentheses/
//Level: Medium

class Solution {
public:

    vector<string> ans;
    void backtrack(int n, int start, int end, string temp){

        if(start == end && start == n) {
            ans.push_back(temp);
            return;
        }
        if(start < n) backtrack(n, start + 1, end, temp + '(');
        if(end < start) backtrack(n, start, end + 1, temp + ')');

    }

    vector<string> generateParenthesis(int n) {
        string a = "";
        
        backtrack(n,0,0,a);

        return ans;

    }
};
//Question: https://leetcode.com/problems/letter-combinations-of-a-phone-number/
//Level: Medium


//solution: 1 recursive (better sol)

class Solution {
public:

    string change(char a){
        if(a == '2'){
            return "abc";
        }
        if(a == '3'){
            return "def";
        }
        if(a == '4'){
            return "ghi";
        }
        if(a == '5'){
            return "jkl";
        }
        if(a == '6'){
            return "mno";
        }
        if(a == '7'){
            return "pqrs";
        }
        if(a == '8'){
            return "tuv";
        }
        if(a == '9'){
            return "wxyz";
        }

        return " ";
    }

    vector<string> letterCombinations(string digits) {
        
        vector<string> temp = {""};

        if(digits.size() == 0){
            temp.clear();
            return temp;
        }

        for(int i = 0; i < digits.size(); i++){
            vector<string> s;
            for(int j = 0; j < temp.size(); j++){
                string t = change(digits[i]);
                for(int k = 0; k < t.size(); k++){
                    s.push_back(temp[j] + t[k]);
                }
            }
            temp = s;
        }
        return temp;


    }
};









//solution: 2 backtracking

class Solution {
public:

    string change(char a){
        if(a == '2'){
            return "abc";
        }
        if(a == '3'){
            return "def";
        }
        if(a == '4'){
            return "ghi";
        }
        if(a == '5'){
            return "jkl";
        }
        if(a == '6'){
            return "mno";
        }
        if(a == '7'){
            return "pqrs";
        }
        if(a == '8'){
            return "tuv";
        }
        if(a == '9'){
            return "wxyz";
        }

        return " ";
    }

    vector<string> ans;


    void backtrack(vector<string>& temp, string s, int index){

        if(index == temp.size()){
            ans.push_back(s);
            return;
        }

        for(int i = 0; i < temp[index].size(); i++){
            s.push_back(temp[index][i]);
            backtrack(temp, s, index + 1);
            s.pop_back();
        }

    }

    vector<string> letterCombinations(string digits) {
        
        if(digits.empty()) return {};

        vector<string> store;
        
        for(int i = 0; i< digits.size(); i++){
            string a = change(digits[i]);
            store.push_back(a);
        }

        backtrack(store, "", 0);

        return ans;
        
    }
};
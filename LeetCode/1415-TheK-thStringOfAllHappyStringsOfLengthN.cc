//Question: https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/?envType=daily-question&envId=2025-02-19
//Level: Medium

class Solution {
public:

    void backtrack(string &ans, int n, int k, int &counter, string temp){

        if(temp.size() == n){
            counter++;
            if(counter == k) ans = temp;
            return;
        }

        vector<char> dir = {'a', 'b', 'c'};

        for(int i = 0; i < 3; i++){

            if(temp.size() != 0){
                char prev = temp[temp.size() - 1];
                if(prev == dir[i]) continue;
            }
            backtrack(ans, n, k, counter, temp + dir[i]);

        }

        return;

    }

    string helper(int n, int k){

        string ans = "";
        int counter = 0;

        backtrack(ans, n, k, counter, "");

        return ans;

    }

    string getHappyString(int n, int k) {

        return helper(n, k);

    }
};

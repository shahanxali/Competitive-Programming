//Question: https://leetcode.com/problems/additive-number/description/
//Level: Medium

class Solution {
    bool dfs(long long n1, long long n2, string s, bool end){

        if(s.empty() && end){
            return true;
        }

        string t = to_string(n1+n2);
        int len = t.length();
        if(s.substr(0, len) != t) {
            return false;
        }
        
        return dfs(n2, n1+n2, s.substr(len), true); 

    }
public:
    bool isAdditiveNumber(string s) {

        int n = s.length();

        for(int i = 1; i < n-1; i++){

            string s1 = s.substr(0, i);
            long long n1 = stoll(s1);
            if(to_string(n1) != s1) break;

            for(int j = i + 1; j < n; j++){

                string s2 = s.substr(i, j-i);
                long long n2 = stoll(s2);
                if(to_string(n2) != s2)
                    break;
                if(dfs(n1, n2, s.substr(j), false))
                    return true;

            }
        }

        return false;

    }
};

//Question: https://leetcode.com/problems/unique-length-3-palindromic-subsequences/?envType=daily-question&envId=2025-01-04
//Level: Medium

class Solution {
public:
    int countPalindromicSubsequence(string s) {

        unordered_set<char> store, sto;
        vector<int> strun;

        int countunique = 0, ans = 0;

        for(auto c : s){
            if(store.find(c) == store.end()){
                countunique++;
                store.insert(c);
            }
            strun.push_back(countunique);
        }


        for(int i = 0; i < s.size() - 1; i++){

            if(sto.find(s[i]) == sto.end()){
                int j = s.size() - 1;

                while(j > i && s[i] != s[j]){
                    j--;
                }

                unordered_set<char> temp;
                int o = 0;
                for(int l = i + 1; l < j; l++){
                    if(temp.find(s[l]) == temp.end()){
                        temp.insert(s[l]);
                        o++;
                    }
                }
                ans += o;

                sto.insert(s[i]);

            }
        }

        return ans;


    }
};

//Question: https://leetcode.com/problems/longest-palindrome/
//Level: Easy

class Solution {
public:
    int longestPalindrome(string s) {
        
        map<char, int> store;
        int count = 0;
        bool ifo = false;

        for(int i = 0; i < s.length(); i++){
            store[s[i]]++;
        }

        for(const auto pair : store){

            if((pair.second == 1) && !ifo){
                ifo = true;
                count++;
            }
            else if((pair.second >= 2) && (pair.second % 2 == 0)){
                count += (pair.second);
            }
            else if((pair.second >= 2) && (pair.second % 2 != 0)){
                count += (pair.second - 1);
                if(!ifo){
                    ifo = true;
                    count++;
                }
            }

        }

        return count;


    }
};
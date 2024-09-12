//Question: https://leetcode.com/problems/count-the-number-of-consistent-strings/?envType=daily-question&envId=2024-09-12
//Level: Easy

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {

        vector<bool> store(27, false);

        for(int i = 0; i < allowed.size(); i++){
            store[int(allowed[i]) - 97] = true;
        }

        int count = 0;

        for(int i = 0; i < words.size(); i++){

            bool isval = true;
            for(int j = 0; j < words[i].size(); j++){
                if(!(store[int(words[i][j]) - 97])){
                    isval = false;
                    break;
                }
            }
            if(isval){
                count++;
            }

        }

        return count;

    }
};

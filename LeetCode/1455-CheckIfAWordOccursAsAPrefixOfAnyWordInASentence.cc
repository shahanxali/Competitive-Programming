//Question: https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/?envType=daily-question&envId=2024-12-02
//Level: Easy

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {

        int pointer2 = 0, count = 1;
        bool check = true;

        for(auto s : sentence){

            if(searchWord[pointer2] == s && check) pointer2++;
            else{
                pointer2 = 0;
                check = false;
            }

            if(pointer2 == searchWord.size()) return count;

            if(s == ' '){
                count++;
                check = true;
            }


        }

        return -1;

    }
};

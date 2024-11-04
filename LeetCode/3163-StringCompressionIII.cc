//Question: https://leetcode.com/problems/string-compression-iii/?envType=daily-question&envId=2024-11-04
//Level: Medium


class Solution {
public:
    string compressedString(string word) {

        string ans = "";
        int point = 0;

        while (point < word.size()) {

            char currentChar = word[point];
            int charcount = 1;

            while (point + 1 < word.size() && word[point + 1] == currentChar){

                charcount++;
                point++;

                if (charcount == 9) {
                    ans += to_string(charcount) + currentChar;
                    charcount = 0;
                }

            }

            if (charcount > 0){
                ans += to_string(charcount) + currentChar;
            }

            point++;

        }

        return ans;
    }
};

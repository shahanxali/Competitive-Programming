//Quetion: https://leetcode.com/problems/make-string-a-subsequence-using-cyclic-increments/?envType=daily-question&envId=2024-12-04
//Level: Medium

class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {

        int p1 = 0, p2 = 0;

        while(p1 < str1.size() && p2 < str2.size()){

            int temp1 = int(str1[p1]), temp2 = int(str2[p2]);
            if((temp2 == 97 && temp1 == 122) || temp2 - 1 == temp1 || temp2 == temp1){
                p2++;
            }

            p1++;

        }
        if(p2 == str2.size()) return true;
        return false;

    }
};

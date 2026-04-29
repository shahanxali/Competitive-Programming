//Question: https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-i/description/?envType=daily-question&envId=2026-03-29
//Level: Easy

class Solution {
public:
    bool canBeEqual(string s1, string s2) {

        if(!((s1[0] == s2[0] && s1[2] == s2[2]) || (s1[0] == s2[2] && s1[2] == s2[0]))) return false;

        if(!((s1[1] == s2[1] && s1[3] == s2[3]) || (s1[1] == s2[3] && s1[3] == s2[1]))) return false;

        return true;

    }
};

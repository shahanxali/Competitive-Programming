//Question: https://leetcode.com/problems/rotate-string/description/?envType=daily-question&envId=2024-11-03
//Level: Easy

class Solution {
public:
    bool rotateString(string s, string goal) {

        string temp = goal;
        int a = 1;

        if(s == temp) return true;
        temp = temp.substr(1, temp.size() - 1) + temp[0];

        while(temp != goal){
            if(s == temp) return true;
            temp = temp.substr(1, temp.size() - 1) + temp[0];
        }

        return false;


    }
};

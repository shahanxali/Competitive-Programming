//Question: https://leetcode.com/problems/count-and-say/?envType=daily-question&envId=2025-04-18
//Level: Medium

class Solution {
public:

    string recur(int n){

        if(n == 1) return "1";

        string temp = recur(n - 1);
        string a = "";

        for(int i = 0; i < temp.size(); i++){
            int j = i, count = 0;
            while(temp[j] == temp[i]){
                i++;
                count++;
            }
            i--;
            a += to_string(count) + temp[i];
        }

        return a;

    }

    string countAndSay(int n) {
        return recur(n);
    }
};

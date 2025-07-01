//Question: https://leetcode.com/problems/find-the-original-typed-string-i/?envType=daily-question&envId=2025-07-01
//Level: Easy

class Solution {
public:
    int possibleStringCount(string words) {

        int ans = 1;

        for(int i = 0; i < words.size(); i++){

            int count = 1, j = i + 1;
            char temp = words[i];
            while(j < words.size() && words[j] == temp){
                j++;
                count++;
            }
            i = j - 1;

            ans += (count - 1);


        }

        return ans;

    }
};

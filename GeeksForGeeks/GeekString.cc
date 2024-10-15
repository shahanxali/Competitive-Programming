//Question: https://practice.geeksforgeeks.org/contest/gfg-weekly-176-rated-contest/problems

class Solution {
  public:
    bool hasGeekSubsequence(string str) {
        // code here

        string g = "geek";
        int gpoint = 0;
        int j = 0;

        for (int i = 0; i < str.size() && j < 4; i++) {
            if (str[i] == g[j]) {
                j++;
            }
        }

        return j == 4;

    }
};

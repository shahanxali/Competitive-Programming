//Question: https://practice.geeksforgeeks.org/contest/gfg-weekly-176-rated-contest/problems

class Solution {
  public:

    int countPalindromicSubstrings(string s, int k) {

        if (k > s.size()) return 0;

        vector<int> freq(26, 0);
        int oddCount = 0;
        int ans = 0;

        //Creating window
        for (int i = 0; i < k; i++) {

            int index = s[i] - 'a';
            freq[index]++;
            if (freq[index] % 2 == 0) oddCount--;
            else oddCount++;

        }

        if (oddCount <= 1) ans++;

        // Slide the window over the string
        for (int i = k; i < s.size(); i++) {

            int addIndex = s[i] - 'a';
            freq[addIndex]++;
            if (freq[addIndex] % 2 == 0) oddCount--;
            else oddCount++;

            int removeIndex = s[i - k] - 'a';
            freq[removeIndex]--;
            if (freq[removeIndex] % 2 == 0) oddCount--;
            else oddCount++;

            if (oddCount <= 1) ans++;

        }

        return ans;

    }
};

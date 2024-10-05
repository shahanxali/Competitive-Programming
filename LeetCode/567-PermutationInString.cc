//Question: https://leetcode.com/problems/permutation-in-string/?envType=daily-question&envId=2024-10-05
//Level: Medium

class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if (s1.size() > s2.size()) return false;


        unordered_map<char, int> store;
        for (auto c : s1) store[c]++;


        int left = 0;
        int matchCount = 0;

        for (int right = 0; right < s2.size(); right++) {

            char rightChar = s2[right];
            if (store.find(rightChar) != store.end()) {

                store[rightChar]--;
                if (store[rightChar] == 0) {
                    matchCount++;
                }

            }


            if (right - left + 1 > s1.size()) {

                char leftChar = s2[left];
                left++;
                if (store.find(leftChar) != store.end()) {
                    if (store[leftChar] == 0) {
                        matchCount--;
                    }
                    store[leftChar]++;
                }

            }

            if (matchCount == store.size()) {
                return true;
            }

        }

        return false;
    }
};

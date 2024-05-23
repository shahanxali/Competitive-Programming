//Question: https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
//Level: Medium


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charIndex;
        int start = 0, maxLength = 0;

        for (int i = 0; i < s.length(); ++i) {
            if (charIndex.find(s[i]) != charIndex.end() && charIndex[s[i]] >= start) {
                start = charIndex[s[i]] + 1;
            }

            charIndex[s[i]] = i;
            maxLength = max(maxLength, i - start + 1);
        }

        return maxLength;
    }
};

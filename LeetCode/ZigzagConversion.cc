//Question: https://leetcode.com/problems/zigzag-conversion/description/
//Level: Medium


class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.length()) {
            return s; // No change needed for 1 row or numRows >= length of string
        }

        string ans;
        int see = (2 * numRows) - 2;

        for (int i = 0; i < numRows; i++) {
            for (int j = i; j < s.length(); j += see) {
                ans.push_back(s[j]);

                if (i != 0 && i != numRows - 1 && (j + see - 2 * i) < s.length()) {
                    ans.push_back(s[j + see - 2 * i]);
                }
            }
        }

        return ans;
    }
};
//Question: https://leetcode.com/problems/compare-version-numbers/description/
//Level: Medium

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int l = 0, m = 0;
        
        while (l < version1.size() || m < version2.size()) {
            int count1 = 0, count2 = 0;
            
            // Extract number from version1
            while (l < version1.size() && version1[l] != '.') {
                count1 = count1 * 10 + (version1[l] - '0');
                l++;
            }
            
            // Extract number from version2
            while (m < version2.size() && version2[m] != '.') {
                count2 = count2 * 10 + (version2[m] - '0');
                m++;
            }
            
            // Compare segment numbers
            if (count1 > count2) {
                return 1;
            } else if (count1 < count2) {
                return -1;
            }
            
            // Move to next segment
            l++;
            m++;
        }
        
        // Versions are equal
        return 0;
    }
};

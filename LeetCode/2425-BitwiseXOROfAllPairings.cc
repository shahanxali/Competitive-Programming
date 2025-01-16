//Question: https://leetcode.com/problems/bitwise-xor-of-all-pairings/description/?envType=daily-question&envId=2025-01-16
//Level: Medium

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {

        int a = nums1.size(), b = nums2.size();
        int ans = 0;

        if(a % 2 != 0){
            for(int num : nums2) ans ^= num;
        }
        if(b % 2 != 0){
            for(int num : nums1) ans ^= num;
        }

        return ans;

    }
};

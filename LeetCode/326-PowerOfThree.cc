//Question: https://leetcode.com/problems/power-of-three/?envType=daily-question&envId=2025-08-13
//Level: Easy

class Solution {
public:
    bool isPowerOfThree(int n) {

        if(n <= 0) return false;

        int div = pow(3, 19);

        return div % n == 0;

    }
};

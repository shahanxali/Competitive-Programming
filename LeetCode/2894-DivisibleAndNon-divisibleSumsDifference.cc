//Question: https://leetcode.com/problems/divisible-and-non-divisible-sums-difference/?envType=daily-question&envId=2025-05-27
//Level: Easy

class Solution {
public:
    int differenceOfSums(int n, int m) {

        int lastterm = (n / m) * m, noterm = (lastterm / m);
        int tot = n * (n + 1) / 2, msum = (m * noterm) + (m * (((noterm - 1) * noterm) / 2));

        return tot - msum - msum;

    }
};

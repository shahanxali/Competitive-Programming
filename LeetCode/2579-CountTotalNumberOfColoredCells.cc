//Question: https://leetcode.com/problems/count-total-number-of-colored-cells/?envType=daily-question&envId=2025-03-05
//Level: Medium

class Solution {
public:
    long long coloredCells(int n) {

        long long a = (long long)(n - 1) * (long long)(n - 1);
        return (2 * a) + (1 + ((n - 1) * 2));

    }
};

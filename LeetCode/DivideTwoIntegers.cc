//Question: https://leetcode.com/problems/divide-two-integers/description/
//Level: Medium

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0 || (dividend == INT_MIN && divisor == -1)) {
            return INT_MAX;
        }

        long long ldividend = abs(static_cast<long long>(dividend));
        long long ldivisor = abs(static_cast<long long>(divisor));
        long long result = 0;

        while (ldividend >= ldivisor) {
            long long temp = ldivisor;
            long long multiple = 1;

            // Use bit manipulation to speed up division
            while (ldividend >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }

            ldividend -= temp;
            result += multiple;
        }

        // Apply the sign to the result
        result *= ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;

        // Check for overflow
        if (result > INT_MAX) {
            return INT_MAX;
        } else if (result < INT_MIN) {
            return INT_MIN;
        } else {
            return static_cast<int>(result);
        }
    }
};

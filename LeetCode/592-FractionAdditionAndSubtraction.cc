//Question: https://leetcode.com/problems/fraction-addition-and-subtraction/description/?envType=daily-question&envId=2024-08-23
//Level: Medium


class Solution {
public:
    string fractionAddition(string expression) {

        int numerator = 0, denominator = 1, n = expression.size();
        int i = 0;

        while (i < n) {

            int sign = 1;

            if (expression[i] == '-' || expression[i] == '+') {
                sign = expression[i] == '-' ? -1 : 1;
                i++;
            }

            int num = 0, den = 0;

            //It may be that the digits at first at from 0-9 but after some time it is possible
            //that the number become greater that 2 digit, that's why while loop
            while(i < n && isdigit(expression[i]))
                num = num * 10 + (expression[i++] - '0');
            

            i++;  // skip the '/'

            while(i < n && isdigit(expression[i]))
                den = den * 10 + (expression[i++] - '0');
            

            numerator = numerator * den + sign * num * denominator;
            denominator *= den;

            // Simplify the fraction after each operation
            int lcm = gcd(abs(numerator), denominator);
            numerator /= lcm;
            denominator /= lcm;

        }


        return to_string(numerator) + "/" + to_string(denominator);



    }
};

//Question: https://leetcode.com/problems/sum-of-square-numbers/
//Level: Medium

class Solution {
public:
    bool judgeSquareSum(int c) {
        long long a = 0, b = sqrt(c); 

        while (a <= b) {
            long long d = a * a + b * b;
            if (d == c) {
                return true;
            } else if (d < c) {
                a++;
            } else {
                b--;
            }
        }
        return false;
    }
};


//Daily again, same 

class Solution {
public:
    bool judgeSquareSum(int c) {
        
        long long a = 0;
        long long b = sqrt(c);

        while(a <= b){

            long long d = (a * a) + (b * b);

            if (d == c) {
                return true;
            }
            else if (d < c) {
                a++;
            }
            else {
                b--;
            }

        }

        return false;

    }
};
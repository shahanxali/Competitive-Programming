//Question: https://leetcode.com/problems/powx-n/
//Level: Medium

class Solution {
public:

    double power(double x, int n){

        if(n == 0) return 1;
        if(n == 1) return x;

        if(n % 2 != 0) return power(x * x, n / 2) * x;

        return power(x * x, n / 2);

    }

    double myPow(double x, int a) {

        double ans;
        long long n = a;
        if(n < 0){
            ans = power(1 / x, -n);
        }
        else{
            ans = power(x, n);
        }

        return ans;

    }
};

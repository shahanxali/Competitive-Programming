//Question: https://leetcode.com/problems/2-keys-keyboard/
//Level: Medium

//Dynamic Programming Part 1

//Recursive Solution

class Solution {
public:

    int count = 0;

    int finmin(int n){

        if(n == 1){
            return  1;
        }

        for(int i = (n - 1); i >= 2; i--){

            if((n % i) == 0){
                return i;
            }

        }

        return n;
        
    }

    void recur(int n, int final){

        int fac = finmin(n);

        if(n == fac){
            count += n;
            return;
        }


        recur(fac, final);
        count += (n / fac); 

        return;

    }

    int minSteps(int n) {

        if(n == 1){
            return 0;
        }
        
        recur(n, n);

        return count;

    }
};


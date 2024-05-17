Question: https://leetcode.com/problems/reverse-integer/description/
Level: Medium

class Solution {
public:
    int reverse(int x) {
    
        long int ans = 0;
        while(x!=0){
            ans = (ans*10) + (x%10);
            x = x/10;
        }
        if(ans <= -2147483648 || ans >= 2147483648){
            ans = 0;
        }
        return ans;

    }
};



//Scond type:

class Solution {
public:
    int reverse(int x) {
    
        int ans = 0;

        while(x!=0){

            if(ans > (INT_MAX / 10) || ans < (INT_MIN / 10)){
                return 0;
            }

            ans = (ans * 10) + (x % 10);
            x = x/10;
        }

        return ans;

    }
};
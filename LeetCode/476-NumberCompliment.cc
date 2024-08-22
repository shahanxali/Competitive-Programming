//Question: https://leetcode.com/problems/number-complement/description/?envType=daily-question&envId=2024-08-22
//Level: Easy

class Solution {
public:
    int findComplement(int num) {
        
        int forxor = 0;
        int count = 0;
        int n = num;
        while(n != 0){
            forxor += pow(2, count);
            count++;
            n /= 2;
        }


        return num ^ forxor;

    }
};
//Question: https://leetcode.com/problems/sum-of-digits-of-string-after-convert/description/?envType=daily-question&envId=2024-09-03
//Level: Easy

class Solution {
public:
    int getLucky(string s, int k) {
        long long sum = 0;
        
        // Convert each character to its corresponding number and sum the digits
        for(char c : s) {
            int num = c - 'a' + 1; // convert character to number
            while(num > 0) {
                sum += num % 10; // sum each digit of the number
                num /= 10;
            }
        }

        // Perform k-1 more transformations, since we already summed digits once
        while(--k > 0) {
            long long newSum = 0;
            while(sum > 0) {
                newSum += sum % 10;
                sum /= 10;
            }
            sum = newSum;
        }
        
        return sum;
    }
};


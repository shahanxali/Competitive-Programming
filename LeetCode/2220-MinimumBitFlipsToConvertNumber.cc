//Question: https://leetcode.com/problems/minimum-bit-flips-to-convert-number/?envType=daily-question&envId=2024-09-11
//Level: Easy

//SOLUTION 1: Not Good

class Solution {
public:
    int minBitFlips(int start, int goal) {

        bitset<32> bin1(start);
        string small = bin1.to_string();

        bitset<32> bin2(goal);
        string large = bin2.to_string();

        int ans = 0;
        small = (start == min(start, goal) ? small : large);
        large = (start == max(start, goal) ? small : large);

        for(int i = 0; i < small.size(); i++){

            if(bin1[i] != bin2[i]){
                ans++;
            }

        }

        for(int i = 0; i < large.size() - small.size(); i++){
            if(large[large.size() - i - 1]){
                ans++;
            }
        }

        return ans;

    }
};


//SOLUTION 2:

//Better solution

class Solution {
public:
    int minBitFlips(int start, int goal) {

        int ans = 0;
        int xored = start ^ goal;

        while(xored != 0){

            if(xored & 1){
                ans++;
            }

            xored = xored >> 1;

        }

        return ans;

    }
};

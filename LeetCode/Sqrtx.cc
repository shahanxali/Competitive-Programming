//Question: https://leetcode.com/problems/sqrtx/
//Level: Easy


class Solution {
public:
    
    int recur(int x, int start, int end){

        if(start > end)
            return end;

        int mid = start + (end - start) / 2;

        if(mid == x / mid){
            return mid;
        }
        else if(mid < x / mid){
            return recur(x, mid + 1, end);
        }
        else{
            return recur(x, start, mid - 1);
        }

    }

    int mySqrt(int x) {
        if(x == 0)
            return 0;

        return recur(x, 1, x);        
    }
};

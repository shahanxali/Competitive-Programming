//Question: https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/?envType=daily-question&envId=2025-03-12
//Level: Easy

class Solution {
public:
    int maximumCount(vector<int>& nums) {

        int mi = 0, ma = 0;
        for(auto num : nums){
            if(num < 0) mi++;
            else if(num > 0) ma++;
        }

        return max(mi, ma);

    }
};

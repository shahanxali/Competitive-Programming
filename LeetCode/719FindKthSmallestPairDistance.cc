//Question: https://leetcode.com/problems/find-k-th-smallest-pair-distance/description/?envType=daily-question&envId=2024-08-14
//Level: Hard

class Solution {
public:

    int combinations(vector<int> nums, int mid){

        int count = 0, left = 0;

        for(int right = 0; right < nums.size(); right++){

            while(nums[right] - nums[left] > mid){
                left++;
            }
            count += right - left;

        }
        return count;

    }

    int binary(vector<int> nums, int k, int left, int right){

        int mid;
        while(left < right){

            mid = left + (right - left) / 2;

            if(combinations(nums, mid) < k){
                left = mid + 1;
            }
            else{
                right = mid;
            }

        }
        return left;
    }
    

    int smallestDistancePair(vector<int>& nums, int k) {
        
        sort(nums.begin(), nums.end());

        return binary(nums, k, 0, nums.back() - nums.front());

    }
};
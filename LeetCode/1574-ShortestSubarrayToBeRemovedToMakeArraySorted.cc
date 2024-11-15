//Question: https://leetcode.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted/?envType=daily-question&envId=2024-11-15
//Level: Medium

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {

        if(arr.size() == 1) return 0;

        int point1 = 0, point2 = arr.size() - 1;

        for(int i = 0; i < arr.size() - 1; i++){
            if(arr[i] <= arr[i + 1]) point1++;
            else break;
        }
        if(point1 == arr.size() - 1) return 0;
        for(int i = arr.size() - 1; i > 1; i--){
            if(arr[i] >= arr[i - 1]) point2--;
            else break;
        }
        int n = arr.size();
        int ans = min(n - point1 - 1, point2);

        int i = 0, j = point2;

        while(i <= point1 && j < n){
            if(arr[i] <= arr[j]){
                ans = min(ans, j - i - 1);
                i++;
            }
            else{
                j++;
            }
        }

        return ans;

    }
};

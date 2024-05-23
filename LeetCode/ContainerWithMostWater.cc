//Question: https://leetcode.com/problems/container-with-most-water/description/
//Level: Medium

class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int start = 0, end = height.size() - 1, ans = 0;

        while(start < end){

            int area = min(height[start], height[end]) * (end - start);
            ans = max(ans, area);

            if(height[start] < height[end]){
                start++;
            }
            else{
                end--;
            }

        }

        return ans;

    }
};
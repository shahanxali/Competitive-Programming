//Question: https://leetcode.com/problems/trapping-rain-water/
//Level: Hard

class Solution {
public:

    int trap(vector<int>& height) {

        if(height.size() <= 2) return 0;

        vector<int> leftmax(height.size(), 0), rightmax(height.size(), 0);

        leftmax[0] = height[0];
        for(int i = 1; i < height.size(); i++){
            leftmax[i] = max(leftmax[i - 1], height[i]);
        }

        rightmax[height.size() - 1] = height[height.size() - 1];
        for(int i = height.size() - 2; i >= 0; i--){
            rightmax[i] = max(rightmax[i + 1], height[i]);
        }

        int ans = 0;
        for(int i = 1; i < height.size() - 1; i++){

            int a = leftmax[i], b = rightmax[i];
            if(a == height[i] || b == height[i]) continue;
            ans += min(a, b) - height[i];

        }
        return ans;

    }
};

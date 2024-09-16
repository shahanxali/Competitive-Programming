//Question: https://leetcode.com/problems/minimum-time-difference/?envType=daily-question&envId=2024-09-16
//Level: Medium

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> ans;

        // Convert each time string "HH:MM" to minutes since 00:00
        for (int i = 0; i < timePoints.size(); i++) {
            string time = timePoints[i];
            int hours = stoi(time.substr(0, 2));  // Extract hours
            int minutes = stoi(time.substr(3, 2));  // Extract minutes
            int totalMinutes = hours * 60 + minutes;
            ans.push_back(totalMinutes);
        }

        // Sort the time points in minutes
        sort(ans.begin(), ans.end());

        // Add the first time again to handle the circular difference (next day wrap-around)
        ans.push_back(ans[0] + 24 * 60);

        int mini = INT_MAX;

        // Find the minimum difference between consecutive time points
        for (int i = 0; i < ans.size() - 1; i++) {
            mini = min(mini, ans[i + 1] - ans[i]);
        }

        return mini;
    }


};

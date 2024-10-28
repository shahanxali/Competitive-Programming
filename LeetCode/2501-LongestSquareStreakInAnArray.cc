//Question: https://leetcode.com/problems/longest-square-streak-in-an-array/description/?envType=daily-question&envId=2024-10-28
//Level: Medium

class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {

        int ans = -1;
        map<int, bool> mapp;

        for (auto num : nums) mapp[num] = false;

        for (auto& pair : mapp) {
            if (!pair.second) {
                long long temp = static_cast<long long>(pair.first) * pair.first;
                int count = 1;
                pair.second = true;

                while (temp <= INT_MAX && mapp.find(temp) != mapp.end() && !mapp[temp]) {
                    mapp[temp] = true;
                    count++;
                    temp *= temp;
                }
                ans = max(ans, count);
            }
        }

        return ans == 1 ? -1 : ans;

    }

};

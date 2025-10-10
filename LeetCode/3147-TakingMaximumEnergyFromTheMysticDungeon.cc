//Question: https://leetcode.com/problems/taking-maximum-energy-from-the-mystic-dungeon/description/?envType=daily-question&envId=2025-10-10
//Level: Medium

class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {

        int ans = INT_MIN;

        vector<int> temp(energy.size(), 0);

        for(int i = energy.size() - 1; i >= 0; i--){

            if(i + k >= energy.size()) temp[i] = energy[i];
            else temp[i] = energy[i] + temp[i + k];

            ans = max(ans, temp[i]);

        }

        return ans;

    }
};

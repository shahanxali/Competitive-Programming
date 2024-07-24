//Question: https://leetcode.com/problems/sort-the-jumbled-numbers/description/
//Level: Medium

class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {

        vector<pair<int, int>> ans;

        for (int i = 0; i < nums.size(); i++) {
            int original = nums[i];
            int mapped_value = 0;
            int place = 1;
            
            if (original == 0) {
                mapped_value = mapping[0];
            }
            else {
                while (original > 0) {
                    int digit = original % 10;
                    mapped_value = mapping[digit] * place + mapped_value;
                    place *= 10;
                    original /= 10;
                }
            }

            ans.push_back({mapped_value, nums[i]});
        }

        sort(ans.begin(), ans.end(), [](pair<int, int> &p1, pair<int, int> &p2) {
            return p1.first < p2.first;
        });


        vector<int> fin;
        for (int i = 0; i < ans.size(); i++) {
            fin.push_back(ans[i].second);
        }

        return fin;
    }
};


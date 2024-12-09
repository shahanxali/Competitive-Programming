//Question: https://leetcode.com/problems/special-array-ii/?envType=daily-question&envId=2024-12-09
//Level: Medium

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {

        vector<int> store(nums.size(), 0);
        int last = 0;
        store[0] = 0;

        for (int i = 0; i < nums.size() - 1; i++) {
            if ((nums[i] % 2 == 0 && nums[i + 1] % 2 == 0) ||
                (nums[i] % 2 != 0 && nums[i + 1] % 2 != 0)) {
                last = i + 1;
            }
            store[i + 1] = last;
        }

        for(auto a : store) cout << a << " ";

        vector<bool> ans;

        for (const auto& query : queries) {
            int startIndex = query[0];
            int endIndex = query[1];

            ans.push_back(store[endIndex] <= startIndex);
        }

        return ans;
    }
};

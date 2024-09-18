//Question: https://leetcode.com/problems/largest-number/?envType=daily-question&envId=2024-09-18
//Level: Medium

class Solution {
public:

    string largestNumber(vector<int>& nums) {

        bool check = true;
        for(auto& num : nums){
            if(num != 0){
                check = false;
                break;
            }

        }
        if(check){
            return "0";
        }

       sort(nums.begin(), nums.end(), [](int& a, int& b){
        string sa = to_string(a);
        string sb = to_string(b);

        return sa + sb > sb + sa;

       });

        string ans = "";

        for(auto st : nums){
            string temp = to_string(st);
            ans += temp;
        }

        return ans;

    }
};

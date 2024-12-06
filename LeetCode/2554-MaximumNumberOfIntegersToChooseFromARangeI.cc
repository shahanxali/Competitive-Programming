//Question: https://leetcode.com/problems/maximum-number-of-integers-to-choose-from-a-range-i/?envType=daily-question&envId=2024-12-06
//Level: Medium

class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {

        unordered_set<int> sett;
        for(int i = 0; i < banned.size(); i++){
            sett.insert(banned[i]);
        }

        int ans = 0, count = 0;

        for(int i = 1; i <= n; i++){
            if(count + i > maxSum) return ans;
            if(sett.find(i) == sett.end() && count <= maxSum){
                ans++;
                count += i;
            }
        }

        return ans;

    }
};

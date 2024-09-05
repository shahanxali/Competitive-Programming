//Question: https://leetcode.com/problems/find-missing-observations/?envType=daily-question&envId=2024-09-05
//Level: Medium

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        
        int count = 0;
        for(int i = 0; i < rolls.size(); i++){
            count += rolls[i];
        }

        int fin = (mean * (rolls.size() + n)) - count;

        vector<int> ans(n);

        if(fin < n || fin > (6 * n)){
            return {};
        }

        int div = fin / n;
        if(n == 1){
            return {fin};
        }

        for(int i = 0; i <= n - 1; i++){
            ans[i] = div;
        }

        for(int i = 0; i <= (fin % n) - 1; i++){
            ans[i]++;
        }


        return ans;

    }
};

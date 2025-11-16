//Quetion: https://leetcode.com/problems/number-of-substrings-with-only-1s/description/?envType=daily-question&envId=2025-11-16
//Level: Medium

class Solution {
public:
    int numSub(string s) {
        const int MOD = 1000000007;
        int ans = 0;
        int pt = 0;

        while(pt < s.size()){
            int temp = pt;
            if(s[temp] == '1'){
                while(s[temp] == '1') temp++;
            }
            int n = temp - pt;
            int ptemp = (long long)n * (n + 1) % MOD;
            ans += (ptemp / 2);
            pt = temp;
            pt++;
        }
        return ans % MOD;

    }
};

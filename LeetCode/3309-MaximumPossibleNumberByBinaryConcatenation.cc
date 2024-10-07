//Question: https://leetcode.com/problems/maximum-possible-number-by-binary-concatenation/
//Level: Medium

class Solution {
public:
    int maxGoodNumber(vector<int>& nums){

        vector<string> binaries;

        for(int num : nums){
            binaries.push_back(bitset<32>(num).to_string().substr(bitset<32>(num).to_string().find('1')));
        }

        long long maxVal = 0;

        sort(binaries.begin(), binaries.end());

        do{

            string concatenated = binaries[0] + binaries[1] + binaries[2];
            long long decimalValue = stoll(concatenated, nullptr, 2);

            maxVal = max(maxVal, decimalValue);

        }
        while(next_permutation(binaries.begin(), binaries.end()));

        return maxVal;
    }
};

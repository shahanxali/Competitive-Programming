//Question: https://leetcode.com/problems/maximize-happiness-of-selected-children/description/?envType=daily-question&envId=2024-05-09
//Level: Medium

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        
        sort(happiness.begin(), happiness.end(), [](const int a, const int b){
            return b < a;
        });
        long long int count = 0;

        for(int i = 0; i < k; i++){

            int a = happiness[i] - i;
            if(a < 0){
                a = 0;
            }

            count += a;

        }

        return count;

    }
};
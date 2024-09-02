//Question: https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk/description/?envType=daily-question&envId=2024-09-02
//Level: Medium


class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        
        long long sum = 0;
        for(int i = 0; i < chalk.size(); i++){
            sum += chalk[i];
        }

        int b = k % sum;

        cout << b << " ";

        for(int i = 0; i < chalk.size(); i++){
            
            b -= chalk[i];

            if(b < 0){
                return i;
            }
        }

        return 0;

    }
};

